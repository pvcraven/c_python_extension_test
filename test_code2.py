import arcade.native


def test_foo():

    foo = arcade.native.SpriteList()
    assert foo.center_x == 0.0
    foo.center_x = 2.0
    assert foo.center_x == 2.0
    foo.move()
    dir(foo)
    x = arcade.native.SpriteList.__getitem__(foo, 1)
    y = foo[0]
    print(f"Hi: {x} {y}")
    print(foo[0])
