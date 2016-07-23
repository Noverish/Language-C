#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main() {
	ALLEGRO_DISPLAY* display; //윈도우 창 변수 선언
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_BITMAP* bitmap;
	ALLEGRO_SAMPLE* sample;
	ALLEGRO_SAMPLE_ID id;

	float x = 400, y = 300;
	float x1 = 350, y1 = 250, x2 = 450, y2 = 350;
	float tick = 0;

	al_init(); //초기화

	display = al_create_display(800, 600); //윈도우 창 생성
	al_init_primitives_addon(); //add-on 초기화
	timer = al_create_timer(1.0 / 60);// 1/60초 마다 이벤트 생성
	event_queue = al_create_event_queue();
	al_install_keyboard(); //키보드 설치
	al_install_mouse(); //마우스 설치
	al_init_image_addon();//이미지 add-on 초기화

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

	al_start_timer(timer);//타이머를 실행 시킨다

	while (1) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);//event가 발생될 때 까지 기다린다

		if (event.type == ALLEGRO_EVENT_KEY_CHAR) {//키보드가 눌리면
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
			al_clear_to_color(al_map_rgb(0, 117, 200));//창의 배경색 설정
			al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(78, 90, 12));
			al_draw_bitmap(bitmap, x, y, 0);
			al_flip_display();//프로그램 안에서 변경된 내용을 모니터에 출력

			al_get_bitmap_width(bitmap);

		} else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	}

	al_destroy_display(display);//창을 없앤다
	al_destroy_timer(timer);//타이머를 없앤다
	al_destroy_event_queue(event_queue);//event_queue를 없앤다
	al_destroy_bitmap(bitmap);//bitmap을 없앤다
	al_destroy_sample(sample);//sample을 없앤다

	return 0;
}