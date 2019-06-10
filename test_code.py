import arcade.native


def test_sprites():

    sprite_list = arcade.native.SpriteList()
    assert sprite_list.center_x == 0.0
    sprite_list.center_x = 2.0
    assert sprite_list.center_x == 2.0

    sprite_list.move()

    sprite = arcade.native.Sprite()
    assert type(sprite) is arcade.native.Sprite

    sprite = sprite_list[0]
    assert type(sprite) is arcade.native.Sprite

    assert sprite.center_x == 2.0
    sprite_list.center_x = 3.0
    assert sprite.center_x == 3.0
