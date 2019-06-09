extern PyTypeObject SpriteType;

typedef struct {
    PyObject_HEAD
    float *center_x;
    float *center_y;
} SpriteObject;
