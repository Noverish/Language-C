#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

int main() {
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* event_queue;

	float x, y;
	float tick = 0;

	al_init();
	al_init_primitives_addon();

	display = al_create_display(800, 600);

	timer = al_create_timer(1.0 / 60);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_start_timer(timer);

	while (1) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgb(0, 117, 200));

			//x = cosf(tick) * 200 + 0;
			//y = sinf(tick) * 200 + 0;

			x = 0;
			y = 0;
			tick += 0.01;

			al_draw_filled_circle(x, y, 50, al_map_rgb(23, 50, 90));


			al_flip_display();
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}