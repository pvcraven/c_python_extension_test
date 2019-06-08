#include <Python.h>
#include <structmember.h>

// https://github.com/hemakoppula/human_activity_anticipation/blob/master/src/pyobjs/sample.c

typedef struct {
    float center_x;
    float center_y;
    float angle;
    float width;
    float height;
    float texture_coord_1;
    float texture_coord_2;
    float texture_coord_3;
    float texture_coord_4;
    unsigned char color_red;
    unsigned char color_green;
    unsigned char color_blue;
    unsigned char color_alpha;
} SpriteListData;

typedef struct {
    PyObject_HEAD
    SpriteListData* sprite_data;
} SpriteListObject;

/**
 * Deallocate a sprite
 */
static void
SpriteList_dealloc(SpriteListObject *self)
{
    free(self->sprite_data);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

/**
 * Create a new sprite
 */
static PyObject *
SpriteList_new(PyTypeObject *type, PyObject *args, PyObject *kw)
{
    int rc = -1;
    SpriteListObject *self = NULL;
    self = (SpriteListObject *) type->tp_alloc(type, 0);

    if (!self) goto error;

    /* allocate attributes */
    self->sprite_data = malloc(sizeof(SpriteListData));
    if (self->sprite_data == NULL) goto error;

    rc = 0;
error:
    if (rc < 0) {
        Py_XDECREF(self);
    }
    return (PyObject *) self;
}

/**
 * __init__() method
 */
static int
SpriteList_init(SpriteListObject *self, PyObject *args, PyObject *kw)
{
    int rc = -1;
    self->sprite_data->center_x = 0;
    self->sprite_data->center_y = 0;
    self->sprite_data->angle = 0;
    self->sprite_data->width = 0;
    self->sprite_data->height = 0;
    self->sprite_data->texture_coord_1 = 0;
    self->sprite_data->texture_coord_2 = 0;
    self->sprite_data->texture_coord_3 = 0;
    self->sprite_data->texture_coord_4 = 0;
    self->sprite_data->color_red = 255;
    self->sprite_data->color_green = 255;
    self->sprite_data->color_blue = 255;
    self->sprite_data->color_alpha = 255;

    rc = 0;

    return rc;
}

static PyObject *
Custom_get_center_x(SpriteListObject *self, void *closure)
{
    return PyFloat_FromDouble(self->sprite_data->center_x);
}

static int
Custom_set_center_x(SpriteListObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_TypeError, "value is NULL");
        return -1;
    }
    if (!PyFloat_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "The first attribute value must be a float");
        return -1;
    }
    self->sprite_data->center_x = (float)PyFloat_AsDouble(value);
    return 0;
}


static PyObject *
Custom_get_item(SpriteListObject sample, int i) {
    Py_RETURN_NONE;
//  if (i<0) i+=sample.n;
//  if (i>=sample.n) {
//    PyErr_SetString(PyExc_IndexError, "sample index out of range");
//    return NULL;
//  }
//  EXAMPLE e = sample.examples[i];
//  return Py_BuildValue("OO", e.x.py_x, e.y.py_y);
}

static PyObject*
Custom_subscript(SpriteListObject *self, PyObject *item) {
    printf("\n***HI***\n");
    if (PyLong_Check(item)) {
        Py_RETURN_NONE;
    } else if (PySlice_Check(item)) {
        PyErr_SetString(PyExc_TypeError, "Slicing not supported");
        return NULL;
    } else {
        PyErr_SetString(PyExc_TypeError, "Bad index type");
        return NULL;
    }
}

/**
 * move() method
 */
static PyObject *
SpriteList_move(SpriteListObject *self)
{
    Py_RETURN_NONE;
}

/**
 * Hook up Sprite attributes to struct
 */
static PyMemberDef SpriteList_members[] = {
    {NULL}
};

/**
 * Specify Sprite methods
 */
static PyMethodDef SpriteList_methods[] = {
    {"move", (PyCFunction)SpriteList_move, METH_NOARGS, NULL},
    {"__getitem__", (PyCFunction) Custom_get_item,  METH_O, NULL},
    {NULL, NULL, 0, NULL}
};

static PyGetSetDef Custom_getsetters[] = {
    {"center_x", (getter) Custom_get_center_x, (setter) Custom_set_center_x,
     "center x", NULL},
    {NULL}  /* Sentinel */
};

static PyMappingMethods Sample_as_mapping = {
  (lenfunc)0,			/* mp_length */
  (binaryfunc)Custom_subscript,		/* mp_subscript */
  (objobjargproc)0,			/* mp_ass_subscript */
};

/**
 * Specify Sprite class info
 */
static PyTypeObject SpriteListType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "SpriteList",
    .tp_doc = "SpriteList doc",
    .tp_basicsize = sizeof(SpriteListObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = SpriteList_new,
    .tp_init = (initproc) SpriteList_init,
    .tp_dealloc = (destructor) SpriteList_dealloc,
    .tp_members = SpriteList_members,
    .tp_methods = SpriteList_methods,
    .tp_getset = Custom_getsetters,
    .tp_as_mapping = &Sample_as_mapping,
};

/**
 * Specify the module the Sprite class is in
 */
static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "arcade.native",
    NULL,
    -1,
    NULL
};

/**
 * Main method to register Sprite
 */
PyMODINIT_FUNC
PyInit_native(void)
{
    PyObject *m = NULL;
    if (PyType_Ready(&SpriteListType) < 0)
        return NULL;
    if ((m = PyModule_Create(&module)) == NULL)
        return NULL;
    Py_XINCREF(&SpriteListType);
    PyModule_AddObject(m, "SpriteList", (PyObject *) &SpriteListType);
    return m;
}
