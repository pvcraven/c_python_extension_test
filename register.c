#include <Python.h>
#include <structmember.h>
#include "sprite_list.h"

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
