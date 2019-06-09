import arcade.native


def test_sprites():

    sprite_list = arcade.native.SpriteList()
    assert sprite_list.center_x == 0.0
    sprite_list.center_x = 2.0
    assert sprite_list.center_x == 2.0

    sprite_list.move()

    sprite = sprite_list[0]
    assert sprite is None

    sprite = arcade.native.Sprite()
    assert sprite is not None
