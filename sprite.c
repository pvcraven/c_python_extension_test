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

//    self->change_x = 0.0;
//    self->change_y = 0.0;

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
//    self->change_x = 0.0;
//    self->change_y = 0.0;

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
 * get_center_y method
 */
static PyObject *
Custom_get_center_y(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->center_y);
}

/**
 * set_center_y method
 */
static int
Custom_set_center_y(SpriteObject *self, PyObject *value, void *closure)
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
    *self->center_y = (float)PyFloat_AsDouble(value);
    return 0;
}

/**
 * get_change_x method
 */
static PyObject *
Custom_get_change_x(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->change_x);
}

/**
 * set_change_x method
 */
static int
Custom_set_change_x(SpriteObject *self, PyObject *value, void *closure)
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
    *self->change_x = (float)PyFloat_AsDouble(value);
    return 0;
}

/**
 * get_change_y method
 */
static PyObject *
Custom_get_change_y(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->change_y);
}

/**
 * set_change_y method
 */
static int
Custom_set_change_y(SpriteObject *self, PyObject *value, void *closure)
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
    *self->change_y = (float)PyFloat_AsDouble(value);
    return 0;
}


/**
 * get_width method
 */
static PyObject *
Custom_get_width(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->width);
}

/**
 * set_center_x method
 */
static int
Custom_set_width(SpriteObject *self, PyObject *value, void *closure)
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
    *self->width = (float)PyFloat_AsDouble(value);
    return 0;
}

/**
 * get_height method
 */
static PyObject *
Custom_get_height(SpriteObject *self, void *closure)
{
    return PyFloat_FromDouble(*self->height);
}

/**
 * set_heightr_x method
 */
static int
Custom_set_height(SpriteObject *self, PyObject *value, void *closure)
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
    *self->height = (float)PyFloat_AsDouble(value);
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
    {"center_x", (getter) Custom_get_center_x, (setter) Custom_set_center_x, "center x", NULL},
    {"center_y", (getter) Custom_get_center_y, (setter) Custom_set_center_y, "center y", NULL},
    {"change_x", (getter) Custom_get_change_x, (setter) Custom_set_change_x, "change x", NULL},
    {"change_y", (getter) Custom_get_change_y, (setter) Custom_set_change_y, "change y", NULL},
    {"width", (getter) Custom_get_width, (setter) Custom_set_width, "width", NULL},
    {"height", (getter) Custom_get_height, (setter) Custom_set_height, "height", NULL},
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


