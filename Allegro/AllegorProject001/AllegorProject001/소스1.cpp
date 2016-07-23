#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main() {
	ALLEGRO_DISPLAY* display; //������ â ���� ����
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_BITMAP* bitmap;
	ALLEGRO_SAMPLE* sample;
	ALLEGRO_SAMPLE_ID id;

	float x = 400, y = 300;
	float x1 = 350, y1 = 250, x2 = 450, y2 = 350;
	float tick = 0;

	al_init(); //�ʱ�ȭ

	display = al_create_display(800, 600); //������ â ����
	al_init_primitives_addon(); //add-on �ʱ�ȭ
	timer = al_create_timer(1.0 / 60);// 1/60�� ���� �̺�Ʈ ����
	event_queue = al_create_event_queue();
	al_install_keyboard(); //Ű���� ��ġ
	al_install_mouse(); //���콺 ��ġ
	al_init_image_addon();//�̹��� add-on �ʱ�ȭ

	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);


	bitmap = al_load_bitmap("resource/overwatch.png");

	sample = al_load_sample("resource/overwatch.wav");
	if (sample) {
		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id);

		al_rest(10.0);

		al_stop_sample(&id);
	}

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);//Ÿ�̸Ӹ� ���� ��Ų��

	while (1) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);//event�� �߻��� �� ���� ��ٸ���

		if (event.type == ALLEGRO_EVENT_KEY_CHAR) {//Ű���尡 ������
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				y -= 2; break;
			case ALLEGRO_KEY_S:
				y += 2; break;
			case ALLEGRO_KEY_A:
				x -= 2; break;
			case ALLEGRO_KEY_D:
				x += 2; break;
			}
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button == 1) {
				float centerX = event.mouse.x;
				float centerY = event.mouse.y;

				x1 = centerX - 50;
				x2 = centerX + 50;
				y1 = centerY - 50;
				y2 = centerY + 50;
			}
		} else if (event.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgb(0, 117, 200));//â�� ���� ����
			al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(78, 90, 12));
			al_draw_bitmap(bitmap, x, y, 0);
			al_flip_display();//���α׷� �ȿ��� ����� ������ ����Ϳ� ���

			al_get_bitmap_width(bitmap);

		} else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	}

	al_destroy_display(display);//â�� ���ش�
	al_destroy_timer(timer);//Ÿ�̸Ӹ� ���ش�
	al_destroy_event_queue(event_queue);//event_queue�� ���ش�
	al_destroy_bitmap(bitmap);//bitmap�� ���ش�
	al_destroy_sample(sample);//sample�� ���ش�

	return 0;
}