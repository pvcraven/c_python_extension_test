import arcade_native


def test_sprites():

    sprite_list = arcade_native.SpriteList()
    sprite_list.move()

    sprite = arcade_native.Sprite()
    assert type(sprite) is arcade_native.Sprite

    sprite_1 = sprite_list[0]
    assert type(sprite_1) is arcade_native.Sprite

    sprite_2 = sprite_list[1]
    assert type(sprite_2) is arcade_native.Sprite

    assert sprite_1.center_x == 0.0
    assert sprite_2.center_x == 0.0
    assert sprite_1.center_y == 0.0
    assert sprite_2.center_y == 0.0

    assert sprite_1.change_x == 0.0
    # assert sprite_2.change_x == 0.0
    # assert sprite_1.change_y == 0.0
    # assert sprite_2.change_y == 0.0

    sprite_1.width = 64.0
    sprite_1.height = 64.0

    sprite_2.width = 64.0
    sprite_2.height = 64.0

    sprite_list.dump()

    sprite_1.center_x = 3.5
    sprite_2.center_x = 4.0

    assert sprite_1.center_x == 3.5
    assert sprite_2.center_x == 4.0

    sprite_1.change_x = 1.0
    sprite_1.change_y = 1.0

    assert sprite_1.change_x == 1.0
    assert sprite_1.change_y == 1.0

    sprite_list.dump()

    assert len(sprite_list) == 100
