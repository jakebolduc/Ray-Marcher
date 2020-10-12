using json = nlohmann::json;

namespace vector{
	void from_json(const json & j, vector & v){
		j.at(0).get_to(v.x);
		j.at(1).get_to(v.y);
		j.at(2).get_to(v.z);
	}
}

namespace raymarch{

	void from_json(const json & j, RaymarchScene & scene){
		for (int i = 0; i < j.size(); i++) {
			std::string type = j.at(i).at("type").get<std::string>();
			if(type == "sdfSphere"){
				scene.addObject(new raymarch::sdfSphere(j.at(i).at("radius").get<VECT_FLOAT>(),j.at(i).at("pos").get<vector::vector>()));
			}
			else{
				std::cout << "unknown object: " << j.at(i).at("type").get<std::string>() << "\n";
			}
			}
		}
	}
