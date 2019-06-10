import arcade.native


def test_sprites():

    sprite_list = arcade.native.SpriteList()
    sprite_list.move()

    sprite = arcade.native.Sprite()
    assert type(sprite) is arcade.native.Sprite

    sprite_1 = sprite_list[0]
    assert type(sprite_1) is arcade.native.Sprite

    sprite_2 = sprite_list[1]
    assert type(sprite_2) is arcade.native.Sprite

    assert sprite_1.center_x == 0.0
    assert sprite_2.center_x == 0.0

    sprite_1.center_x = 3.5
    sprite_2.center_x = 4.0

    assert sprite_1.center_x == 3.5
    assert sprite_2.center_x == 4.0

