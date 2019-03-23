#include "main.h"


int main()
{
	//std::string mmap_dir = "C:\\Users\\Administrator\\Desktop\\mmaps\\";
	std::string mmap_dir = "H:\\mmaps\\";
	int map_id = 0;

	AmeisenNavigation* ameisen_nav = new AmeisenNavigation(mmap_dir);

	std::cout << "-> Preloading Eastern Kingdoms & Kalimdor...\n";
	ameisen_nav->LoadMmapsForContinent(0); // Eastern Kingdoms
	ameisen_nav->LoadMmapsForContinent(1); // Kalimdor

	float start[3] = { -8826.562500f, -371.839752f, 71.638428f };
	float end[3] = { -8847.150391f, -387.518677f, 72.575912f };
	float tile_loc[3] = { -8918.406250f, -130.297256f, 80.906364f };

	int path_size;
	float* path;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	ameisen_nav->GetPath(map_id, start, tile_loc, &path, &path_size);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "-> Pathfinding took "<< duration << "ms\n";

	std::cout << "-> Path size: " << path_size << " Nodes\n";

	std::cin.get();
	return 0;
}