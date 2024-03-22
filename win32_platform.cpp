#include <iostream>
#include "utils.cpp"
#include <windows.h>
#include <sstream>

using namespace std;






global_variable  bool running = true;
int mov = 0;

struct Render_State {
	int height, width;
	void* memory;

	BITMAPINFO bitmap_info;

};

global_variable Render_State render_state;


#include "renderer.cpp"
#include "game.cpp"


LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg) {
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		} break;

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			render_state.width = rect.right - rect.left;
			render_state.height = rect.bottom - rect.top;

			int size = render_state.width * render_state.height * sizeof(unsigned int);

			if (render_state.memory) VirtualFree(render_state.memory, 0, MEM_RELEASE);
			render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
			render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
			render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
			render_state.bitmap_info.bmiHeader.biPlanes = 1;
			render_state.bitmap_info.bmiHeader.biBitCount = 32;
			render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;

		} break;

		case WM_KEYDOWN:
		{
			OutputDebugString(L"Key Pressed\n");
			WM_UNICHAR;
			switch (wParam)
			{
				case 0x00: // 0x00
				{
					OutputDebugString(L"0x00 Pressed\n");
				} break;

				case 0x01: // 0x01
				{
					OutputDebugString(L"0x01 Pressed\n");
				} break;

				case 0x02: // 0x02
				{
					OutputDebugString(L"0x02 Pressed\n");
				} break;

				case 0x03: // 0x03
				{
					OutputDebugString(L"0x03 Pressed\n");
				} break;

				case 0x04: // 0x04
				{
					OutputDebugString(L"0x04 Pressed\n");
				} break;

				case 0x05: // 0x05
				{
					OutputDebugString(L"0x05 Pressed\n");
				} break;

				case 0x06: // 0x06
				{
					OutputDebugString(L"0x06 Pressed\n");
				} break;

				case 0x07: // 0x07
				{
					OutputDebugString(L"0x07 Pressed\n");
				} break;

				case 0x08: // 0x08 is the Backspace Key
				{
					OutputDebugString(L"0x08 Pressed (Backspace)\n");
				} break;

				case 0x09: // 0x09 is the Tab Key
				{
					OutputDebugString(L"0x09 Pressed (Tab)\n");
				} break;

				case 0x0a: // 0x09
				{
					OutputDebugString(L"0x0a Pressed\n");
				} break;

				case 0x0b: // 0x09
				{
					OutputDebugString(L"0x0b Pressed\n");
				} break;

				case 0x0c: // 0x09
				{
					OutputDebugString(L"0x0c Pressed\n");
				} break;

				case 0x0d: // 0x09 is the Enter Key
				{
					OutputDebugString(L"0x0d Pressed (Enter)\n");
				} break;

				case 0x0e: // 0x09
				{
					OutputDebugString(L"0x0e Pressed\n");
				} break;

				case 0x0f: // 0x09
				{
					OutputDebugString(L"0x0f Pressed\n");
				} break;

				case 0x10: // 0x10 is the Shift key
				{
					OutputDebugString(L"0x10 Pressed (Shift)\n");
				} break;

				case 0x11: // 0x11 is the Ctrl key
				{
					OutputDebugString(L"0x11 Pressed (Ctrl)\n");
				} break;

				case 0x12: // 0x12
				{
					OutputDebugString(L"0x12 Pressed\n");
				} break;

				case 0x13: // 0x13 is the Pause/Break Key
				{
					OutputDebugString(L"0x13 Pressed (Pause/Break)\n");
				} break;

				case 0x14: // 0x14 is the Caps-Lock Key
				{
					OutputDebugString(L"0x14 Pressed (Caps-Lock)\n");
				} break;

				case 0x15: // 0x15
				{
					OutputDebugString(L"0x15 Pressed\n");
				} break;

				case 0x16: // 0x16
				{
					OutputDebugString(L"0x16 Pressed\n");
				} break;

				case 0x17: // 0x17
				{
					OutputDebugString(L"0x17 Pressed\n");
				} break;

				case 0x18: // 0x18
				{
					OutputDebugString(L"0x18 Pressed\n");
				} break;

				case 0x19: // 0x19
				{
					OutputDebugString(L"0x19 Pressed\n");
				} break;

				case 0x1a: // 0x1a
				{
					OutputDebugString(L"0x1a Pressed\n");
				} break;

				case 0x1b: // 0x1b
				{
					OutputDebugString(L"0x1b Pressed\n");
				} break;

				case 0x1c: // 0x1c
				{
					OutputDebugString(L"0x1c Pressed\n");
				} break;

				case 0x1d: // 0x1d
				{
					OutputDebugString(L"0x1d Pressed\n");
				} break;

				case 0x1e: // 0x1e
				{
					OutputDebugString(L"0x1e Pressed\n");
				} break;

				case 0x1f: // 0x1f
				{
					OutputDebugString(L"0x1f Pressed\n");
				} break;

				case 0x20: // 0x20 is the Space key
				{
					OutputDebugString(L"0x20 Pressed (Space)\n");
				} break;

				case 0x21: // 0x21 is the Page-Up Key
				{
					OutputDebugString(L"0x21 Pressed (Page-Up)\n");
				} break;

				case 0x22: // 0x22 is the Page-Down Key
				{
					OutputDebugString(L"0x22 Pressed (Page-Dowm)\n");
				} break;

				case 0x23: // 0x23 is the End Key
				{
					OutputDebugString(L"0x23 Pressed (End)\n");
				} break;

				case 0x24: // 0x24 is the Home Key
				{
					OutputDebugString(L"0x24 Pressed (Home)\n");
				} break;

				case 0x25: // 0x25 is the Left Key
				{
					OutputDebugString(L"0x25 Pressed (Left)\n");
				} break;

				case 0x26: // 0x26 is the Up Key
				{
					OutputDebugString(L"0x26 Pressed (Up)\n");
				} break;

				case 0x27: // 0x27 is the Right Key
				{
					OutputDebugString(L"0x27 Pressed (Right)\n");
				} break;

				case 0x28: // 0x28 is the Down Key
				{
					OutputDebugString(L"0x28 Pressed (Down)\n");
				} break;

				case 0x29: // 0x29 
				{
					OutputDebugString(L"0x29 Pressed\n");
				} break;

				case 0x2a: // 0x2a 
				{
					OutputDebugString(L"0x2a Pressed\n");
				} break;

				case 0x2b: // 0x2b 
				{
					OutputDebugString(L"0x2b Pressed\n");
				} break;

				case 0x2c: // 0x2c 
				{
					OutputDebugString(L"0x2c Pressed\n");
				} break;

				case 0x2d: // 0x2d is the Insert Key
				{
					OutputDebugString(L"0x2d Pressed (Insert)\n");
				} break;

				case 0x2e: // 0x2e is the Delete Key
				{
					OutputDebugString(L"0x2e Pressed (Delete)\n");
				} break;

				case 0x2f: // 0x2f 
				{
					OutputDebugString(L"0x2f Pressed\n");
				} break;

				case 0x30: // 0x30 is the 0 Key
				{
					OutputDebugString(L"0x30 Pressed (0)\n");
				} break;

				case 0x31: // 0x31 is the 1 Key
				{
					OutputDebugString(L"0x31 Pressed (1)\n");
				} break;

				case 0x32: // 0x32 is the 2 Key
				{
					OutputDebugString(L"0x32 Pressed (2)\n");
				} break;

				case 0x33: // 0x33 is the 3 Key
				{
					OutputDebugString(L"0x33 Pressed (3)\n");
				} break;

				case 0x34: // 0x34 is the 4 Key
				{
					OutputDebugString(L"0x34 Pressed (4)\n");
				} break;

				case 0x35: // 0x35 is the 5 Key
				{
					OutputDebugString(L"0x35 Pressed (5)\n");
				} break;

				case 0x36: // 0x36 is the 6 Key
				{
					OutputDebugString(L"0x36 Pressed (6)\n");
				} break;

				case 0x37: // 0x37 is the 7 Key
				{
					OutputDebugString(L"0x37 Pressed (7)\n");
				} break;

				case 0x38: // 0x38 is the 8 Key
				{
					OutputDebugString(L"0x38 Pressed (8)\n");
				} break;

				case 0x39: // 0x39 is the 9 Key
				{
					OutputDebugString(L"0x39 Pressed (9)\n");
				} break;

				case 0x3a: // 0x3a 
				{
					OutputDebugString(L"0x3a Pressed\n");
				} break;

				case 0x3b: // 0x3b 
				{
					OutputDebugString(L"0x3b Pressed\n");
				} break;

				case 0x3c: // 0x3c 
				{
					OutputDebugString(L"0x3c Pressed\n");
				} break;

				case 0x3d: // 0x3d 
				{
					OutputDebugString(L"0x3d Pressed\n");
				} break;

				case 0x3e: // 0x3e 
				{
					OutputDebugString(L"0x3e Pressed\n");
				} break;

				case 0x3f: // 0x3f 
				{
					OutputDebugString(L"0x3f Pressed\n");
				} break;

				case 0x40: // 0x40 
				{
					OutputDebugString(L"0x40 Pressed\n");
				} break;

				case 0x41: // 0x41 is the A key
				{
					OutputDebugString(L"0x41 Pressed (A)\n");
					bob.left(true);
				} break;

				case 0x42: // 0x42 is the B key
				{
					OutputDebugString(L"0x42 Pressed (B)\n");
				} break;

				case 0x43: // 0x43 is the C key
				{
					OutputDebugString(L"0x43 Pressed (C)\n");
				} break;

				case 0x44: // 0x44 is the D key
				{
					OutputDebugString(L"0x44 Pressed (D)\n");
					bob.right(true);
				} break;

				case 0x45: // 0x45 is the E key
				{
					OutputDebugString(L"0x45 Pressed (E)\n");
				} break;

				case 0x46: // 0x46 is the F key
				{
					OutputDebugString(L"0x46 Pressed (F)\n");
				} break;

				case 0x47: // 0x47 is the G key
				{
					OutputDebugString(L"0x47 Pressed (G)\n");
				} break;

				case 0x48: // 0x48 is the H key
				{
					OutputDebugString(L"0x48 Pressed (H)\n");
				} break;

				case 0x49: // 0x49 is the I key
				{
					OutputDebugString(L"0x4a Pressed (I)\n");
				} break;

				case 0x4a: // 0x4a is the J key
				{
					OutputDebugString(L"0x4a Pressed (J)\n");
				} break;

				case 0x4b: // 0x4b is the K key
				{
					OutputDebugString(L"0x4b Pressed (K)\n");
				} break;

				case 0x4c: // 0x4c is the L key
				{
					OutputDebugString(L"0x4c Pressed (L)\n");
				} break;

				case 0x4d: // 0x4d is the M key
				{
					OutputDebugString(L"0x4d Pressed (M)\n");
				} break;

				case 0x4e: // 0x4e is the N key
				{
					OutputDebugString(L"0x4e Pressed (N)\n");
				} break;

				case 0x4f: // 0x49 is the O key
				{
					OutputDebugString(L"0x4f Pressed (O)\n");
				} break;

				case 0x50: // 0x50 is the P key
				{
					OutputDebugString(L"0x50 Pressed (P)\n");
				} break;

				case 0x51: // 0x51 is the Q key
				{
					OutputDebugString(L"0x51 Pressed (Q)\n");
				} break;

				case 0x52: // 0x52 is the R key
				{
					OutputDebugString(L"0x52 Pressed (R)\n");
				} break;

				case 0x53: // 0x53 is the S key
				{
					OutputDebugString(L"0x53 Pressed (S)\n");
					bob.down(true);
				} break;

				case 0x54: // 0x54 is the T key
				{
					OutputDebugString(L"0x54 Pressed (T)\n");
				} break;

				case 0x55: // 0x55 is the U key
				{
					OutputDebugString(L"0x55 Pressed (U)\n");
				} break;

				case 0x56: // 0x56 is the V key
				{
					OutputDebugString(L"0x56 Pressed (V)\n");
				} break;

				case 0x57: // 0x57 is the W key
				{
					OutputDebugString(L"0x57 Pressed (W)\n");
					bob.up(true);
				} break;

				case 0x58: // 0x58 is the X key
				{
					OutputDebugString(L"0x58 Pressed (X)\n");				
				} break;

				case 0x59: // 0x59 is the Y key
				{
					OutputDebugString(L"0x59 Pressed (Y)\n");				
				} break;

				case 0x5a: // 0x5a is the z key
				{
					OutputDebugString(L"0x5a Pressed (Z)\n");				
				} break;		
			
			}
		} break;

		case WM_KEYUP:
		{
			WM_UNICHAR;
			switch (wParam)
			{
			case 0x57: // 0x57 is the W key
			{
				bob.up(false);
			} break;

			case 0x41: // 0x41 is the A key
			{
				bob.left(false);
			} break;

			case 0x53: // 0x53 is the S key
			{
				bob.down(false);
			} break;

			case 0x44: // 0x44 is the D key
			{
				bob.right(false);
			} break;

			}
		} break;


		case WM_LBUTTONDOWN:
		{

			//POINT cursorPos;

			//// Get the current cursor position
			//if (GetCursorPos(&cursorPos)) {
			//	std::ostringstream oss;
			//	oss << "Mouse X position: " << cursorPos.x << "\n";
			//	oss << "Mouse Y position: " << cursorPos.y << "\n";
			//	OutputDebugStringA(oss.str().c_str());
			//}
			//else {
			//	OutputDebugStringA("Failed to get cursor position.");
			//}




			//HWND hWnd = GetForegroundWindow(); // Get the handle to the foreground window

			//POINT cursorPos;
			//GetCursorPos(&cursorPos); // Get the current cursor position

			//ScreenToClient(hWnd, &cursorPos); // Convert screen coordinates to client coordinates

			//std::ostringstream oss;
			//oss << "Mouse X position relative to window: " << cursorPos.x << "\n";
			//oss << "Mouse Y position relative to window: " << cursorPos.y << "\n";
			//OutputDebugStringA(oss.str().c_str());			



			OutputDebugString(L"Left Click!\n");
		} break;

		case WM_RBUTTONDOWN:
		{
			OutputDebugString(L"Right Click!\n");
		} break;

		

		


		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	return result;
}


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {


	// Create Window Class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = L"Game Window Class";
	window_class.lpfnWndProc = window_callback;

	// Register Class
	RegisterClass(&window_class);

	// Create Window
	HWND window = CreateWindow(window_class.lpszClassName, 
		L"The Testing Grounds", 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		1280, 720, 
		0, 0, 
		hInstance, 0
	);
	HDC hdc = GetDC(window);

	GameSetup();

	float delta_time = 0.01666f;
	LARGE_INTEGER frame_begin_time;
	LARGE_INTEGER frame_end_time;
	QueryPerformanceCounter(&frame_begin_time);

	float performance_frequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);
		performance_frequency = (float)perf.QuadPart;
	}

	while (running) {
		// Input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		// Simulate
		clear_screen(0x555555);
		GameRun();

		// Render
		StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
		
		
		while (true) {
			QueryPerformanceCounter(&frame_end_time);
			delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;

			if (delta_time >= 1.0f / 60.f) {
				break;
			}
		}
			
		frame_begin_time = frame_end_time;		
	}	
}