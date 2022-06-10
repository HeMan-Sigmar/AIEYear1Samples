#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);
	// IN APPLICATION 2 – A user of the named shared memory 
// gain access to a named shared memory block that already exists 
	fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
	sizeHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"sizeMemory");
	return true;

}

void EntityDisplayApp::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
	// close the shared file 
	CloseHandle(fileHandle);
	CloseHandle(sizeHandle);
}


void EntityDisplayApp::Update(float deltaTime) 
{
	Entity* entity = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS,
		0, 0, sizeof(Entity*));
	int* count = (int*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS,
		0, 0, sizeof(int));


	if (count && entity) {
		for (int i = 0; i < *count; i++)
		{
			m_entities.push_back(entity[i]);
		}
	}
	UnmapViewOfFile(entity);
	UnmapViewOfFile(count);
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {
		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}
	m_entities.clear();
	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}
