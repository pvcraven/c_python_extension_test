#include <Python.h>
#include <structmember.h>
#include "sprite.h"


/**
 * Deallocate a sprite
 */
static void
Sprite_dealloc(SpriteObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}

/**
 * Create a new sprite
 */
static PyObject *
Sprite_new(PyTypeObject *type, PyObject *args, PyObject *kw)
{
    int rc = -1;
    SpriteObject *self = NULL;
    self = (SpriteObject *) type->tp_alloc(type, 0);

    if (!self) goto error;

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
Sprite_init(SpriteObject *self, PyObject *args, PyObject *kw)
{
    int rc = -1;
    // Init goes here
    rc = 0;

    return rc;
}

/**
 * get_center_x method
 */
static PyObject *
Custom_get_center_x(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->center_x);
}

/**
 * set_center_x method
 */
static int
Custom_set_center_x(SpriteObject *self, PyObject *value, void *closure)
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
    *self->center_x = (float)PyFloat_AsDouble(value);
    return 0;
}

/**
 * move() method
 */
static PyObject *
Sprite_move(SpriteObject *self)
{
    Py_RETURN_NONE;
}

/**
 * Hook up Sprite attributes to struct
 */
static PyMemberDef Sprite_members[] = {
    {NULL}
};

/**
 * Specify Sprite methods
 */
static PyMethodDef Sprite_methods[] = {
    {"move", (PyCFunction)Sprite_move, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

/**
 * Specify sprite getters/setters
 */
static PyGetSetDef Custom_getsetters[] = {
    {"center_x", (getter) Custom_get_center_x, (setter) Custom_set_center_x,
     "center x", NULL},
    {NULL}  /* Sentinel */
};

/**
 * Specify Sprite class info
 */
PyTypeObject SpriteType = {
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
    .tp_methods = Sprite_methods,
    .tp_getset = Custom_getsetters,
};


