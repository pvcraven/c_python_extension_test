#include <Python.h>
#include <structmember.h>


typedef struct {
    PyObject_HEAD
    float center_x;
    float center_y;
    float change_x;
    float change_y;
    PyObject *foo;
    PyObject *bar;
} SpriteObject;

static void
Sprite_dealloc(SpriteObject *self)
{
    Py_XDECREF(self->foo);
    Py_XDECREF(self->bar);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
Sprite_new(PyTypeObject *type, PyObject *args, PyObject *kw)
{
    int rc = -1;
    SpriteObject *self = NULL;
    self = (SpriteObject *) type->tp_alloc(type, 0);

    if (!self) goto error;

    /* allocate attributes */
    self->foo = PyUnicode_FromString("");
    if (self->foo == NULL) goto error;

    self->bar = PyUnicode_FromString("");
    if (self->bar == NULL) goto error;

    self->center_x = 0.0;
    self->center_y = 0.0;

    rc = 0;
error:
    if (rc < 0) {
        Py_XDECREF(self->foo);
        Py_XINCREF(self->bar);
        Py_XDECREF(self);
    }
    return (PyObject *) self;
}

static int
Sprite_init(SpriteObject *self, PyObject *args, PyObject *kw)
{
    int rc = -1;
    static char *keywords[] = {"foo", "bar", NULL};
    PyObject *foo = NULL, *bar = NULL, *ptr = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kw,
                                    "|OO", keywords,
                                    &foo, &bar))
    {
        goto error;
    }

    if (foo) {
        ptr = self->foo;
        Py_INCREF(foo);
        self->foo = foo;
        Py_XDECREF(ptr);
    }

    if (bar) {
        ptr = self->bar;
        Py_INCREF(bar);
        self->bar = bar;
        Py_XDECREF(ptr);
    }
    rc = 0;
error:
    return rc;
}

static PyObject *
Sprite_move(SpriteObject *self)
//{
//    self->center_x = 0.0;
//    self->center_x += self->change_x;
//    self->center_y += self->change_y;
}

static PyMemberDef Sprite_members[] = {
    {"foo", T_OBJECT_EX, offsetof(SpriteObject, foo), 0, NULL},
    {"bar", T_OBJECT_EX, offsetof(SpriteObject, bar), 0, NULL},
    {"center_x", T_FLOAT, offsetof(SpriteObject, center_x), 0, NULL},
    {"center_y", T_FLOAT, offsetof(SpriteObject, center_y), 0, NULL},
    {"change_x", T_FLOAT, offsetof(SpriteObject, change_x), 0, NULL},
    {"change_y", T_FLOAT, offsetof(SpriteObject, change_y), 0, NULL},
    {NULL}
};

static PyMethodDef Sprite_methods[] = {
    {"move", (PyCFunction)Sprite_move, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static PyTypeObject SpriteType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Sprite",
    .tp_doc = "Sprite doc",
    .tp_basicsize = sizeof(SpriteObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = Sprite_new,
    .tp_init = (initproc) Sprite_init,
    .tp_dealloc = (destructor) Sprite_dealloc,
    .tp_members = Sprite_members,
    .tp_methods = Sprite_methods
};

static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "arcade.native",
    NULL,
    -1,
    NULL
};

PyMODINIT_FUNC
PyInit_native(void)
{
    PyObject *m = NULL;
    if (PyType_Ready(&SpriteType) < 0)
        return NULL;
    if ((m = PyModule_Create(&module)) == NULL)
        return NULL;
    Py_XINCREF(&SpriteType);
    PyModule_AddObject(m, "Sprite", (PyObject *) &SpriteType);
    return m;
}