import arcade.native


def test_foo():

    foo = arcade.native.Sprite()
    print(foo.bar)

    assert foo.bar == ""
    foo.bar = "foo"
    assert foo.bar == "foo"

    assert foo.center_x == 0.0
    foo.center_x = 1.5
    assert foo.center_x == 1.5

    assert foo.center_y == 0.0
    foo.center_y = 1.5
    assert foo.center_y == 1.5

    assert foo.change_x == 0.0
    foo.change_x = 1.5
    assert foo.change_x == 1.5

    assert foo.change_y == 0.0
    foo.change_y = 1.5
    assert foo.change_y == 1.5

    foo.move()

    assert foo.center_x == 3.0
    assert foo.center_y == 3.0
