#include "bouncyball.h"
#include "Enemy.h"
#include "player.h"

BouncyBall p1;
Player bob;

void GameSetup() {
}

void GameRun() {
	//draw_rect_xywh(300, 100, 800, 700, 0xaaaa00);
	//draw_triangle(400, 400, 400, 600, 600, 600, 0x00ff00);
	//draw_rect_xywh(600, 500, 100, 100, RGB(255,0,255));	
	bob.draw();
	p1.draw();
	draw_grid(10, 5, 0x00ff00);
}