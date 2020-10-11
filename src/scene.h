printf("loading scene.json...\n");
//scene.addObject(new raymarch::sdfSphere(15,vector::set(0,0,70)));
//scene.addObject(new raymarch::sdfSphere(10,vector::set(15,0,70)));
json j;
std::ifstream i("scene.json");
i >> j;
i.close();
//std::cout << j.at("foo") << std::endl;

printf("done.\n");
