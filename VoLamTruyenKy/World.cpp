#include "World.h"
#include<iostream>
World::World(){
}

void World::AddPlayer(){
	std::string Name;
	unsigned int cClass = 0, cLevel;
	std::cout << "Nhap ten cua nhan vat:";
	std::cin.ignore();
	while (std::getline(std::cin, Name) && Name.empty()) {
		std::cout << "Ten khong duoc bo trong. ";
	}
	std::cout << "Chon Bang Phai cho nhan vat.\n";
	for (unsigned int id = 0; id < 10; ++id) {
		std::cout << '\t' << id << ". " << getClassName((EClassID)id) << ".\n";
	}
	std::cout << "Lua chon:";
	while (std::cin >> cClass&& cClass < 0 || cClass>9) {
		std::cout << "Vui long nhap trong khoang 0 den 9. ";
	}
	std::cout << "Cap do cua nhan vat:";
	std::cin >> cLevel;
	m_vEntity.push_back(new Player{ cLevel, (EClassID)cClass, Name });
}

void World::AddMonster(){
	std::string Name;
	unsigned int cClass = 0, cLevel, isBoss = 0, cEle = 0;
	std::cout << "Nhap ten cua quai vat:";
	std::cin.ignore();
	while (std::getline(std::cin, Name) && Name.empty()) {
		std::cout << "Ten khong duoc bo trong. ";
	}
	std::cout << "Cap do cua quai vat:";
	std::cin >> cLevel;
	std::cout << "Quai co phai la dau linh khong? (0. Khong, 1.Co):";
	while (std::cin >> isBoss && isBoss < 0 || isBoss>1) {
		std::cout << "Vui long nhap 0 hoac 1. ";
	}
	std::cout << "Hanh cua quai vat:\n(0.He Kim, 1. He Moc, 2. He Thuy, 3. He Hoa, 4. He Tho): ";
	while (std::cin >> cEle && cEle < 0 || cEle>4) {
		std::cout << "Vui long nhap trong khoang 0 den 4. ";
	}

	m_vEntity.push_back(new Monster{ cLevel, (EElementsID)cEle, (bool)isBoss , Name });
}

void World::DisplayEntityInformation(){
	unsigned int index;
	if (!m_vEntity.empty()) {
		std::cout << "Nhap thu tu cua doi tuong can xuat thong tin:\n";
		
		while (std::cin >> index && index<1 || index>m_vEntity.size()) {
			std::cout << "Vui long nhap thu tu hop le:\n";
		}
		std::cout << "Thong tin cua doi tuong thu " << index << '\n';
		m_vEntity[index - 1]->info();
	}
	else {
		std::cout << "Danh sach chua co doi tuong nao.\n";
	}
}

void World::DisplayAllInformation(){
	if (!m_vEntity.empty()) {
		std::cout << "Thong tin tat ca doi tuong trong danh sach.\n";
		std::cout << "__________________________________________________\n";
		for (unsigned int index = 0; index < m_vEntity.size(); ++index) {
			std::cout << "Thong tin cua doi tuong thu " << index + 1 << '\n';
			m_vEntity[index]->info();
			std::cout << "__________________________________________________\n";
		}
	}
	else {
		std::cout << "-----------------Danh sach rong-----------------\n";
	}
}

void World::Comparison(){
	unsigned int indexA, indexB;
	if (m_vEntity.size() > 1) {
		std::cout << "Nhap thu tu cua 2 doi tuong can so sanh.\n";
		std::cout << "Vui long nhap thu tu hop le, khong nhap hai doi tuong trung nhau: ";
		do {
			std::cin >> indexA >> indexB;
		} while (indexA == indexB || indexA<0 || indexB<0 || indexA>m_vEntity.size() || indexB>m_vEntity.size());
		std::cout << "Sat thuong cua doi tuong thu " << indexA << " gay ra cho doi tuong thu " << indexB << " la:" << m_vEntity[indexA - 1]->getDamageDealtTo(*m_vEntity[indexB - 1]) << '\n';
		std::cout << "Sat thuong cua doi tuong thu " << indexB << " gay ra cho doi tuong thu " << indexA << " la:" << m_vEntity[indexB - 1]->getDamageDealtTo(*m_vEntity[indexA - 1]) << '\n';
	}
	else {
		std::cout << "Danh sach phai co it nhat 2 doi tuong.\n";
	}
}

void World::DisplayHighestDamage(){
	Entity* EntHighestDamage = nullptr;
	unsigned int index, highestDamage, damageDealt;
	if (!m_vEntity.empty()) {
		highestDamage = 0;
		index = 0;
		for (unsigned int attacker = 0; attacker < m_vEntity.size(); ++attacker) {
			damageDealt = 0;
			for (unsigned int defender = 0; defender < m_vEntity.size(); ++defender) {
				if (attacker != defender) {
					damageDealt = m_vEntity[attacker]->getDamageDealtTo(*m_vEntity[defender]);
				}
			}
			if (damageDealt > highestDamage) {
				highestDamage = damageDealt;
				index = attacker;
			}
		}
		EntHighestDamage = m_vEntity[index];
		std::cout << "Doi tuong co muc sat thuong cao nhat.\n ";
		EntHighestDamage->info();
	}
	else {
		std::cout << "Danh sach chua co doi tuong nao.\n";
	}
}

void World::Init(){
	unsigned int choice = 0;
	do {
		std::cout << "=============================MENU=================================\n";
		std::cout << "1. Them nguoi choi vao danh sach.\n";
		std::cout << "2. Them quai vat vao danh sach.\n";
		std::cout << "3. Hien thi doi tuong co muc sat thuong cao nhat trong danh sach.\n";
		std::cout << "4. So sanh sat thuong giua hai doi tuong.\n";
		std::cout << "5. Xuat thong tin cua mot doi tuong.\n";
		std::cout << "6. Xuat toan bo thong tin cac doi tuong trong danh sach.\n";
		std::cout << "7. Thoat tro choi.\n";
		std::cout << "=============================END==================================\n";
		std::cout << "Nhap lua chon:";
		while (std::cin >> choice && choice > 7 || choice < 1) {
			std::cout << "Vui long nhap lai lua chon. ";
		}
		switch (choice) {
			case 1: {
				std::cout << "__________________________________________________\n";
				AddPlayer();
				std::cout << "__________________________________________________\n";
				break;
			}
			case 2: {
				std::cout << "__________________________________________________\n";
				AddMonster();
				std::cout << "__________________________________________________\n";
				break;
			}
			case 3: {
				std::cout << "__________________________________________________\n";
				DisplayHighestDamage();
				std::cout << "__________________________________________________\n";
				break;
			}
			case 4: {
				std::cout << "__________________________________________________\n";
				Comparison();
				std::cout << "__________________________________________________\n";
				break;
			}
			case 5: {
				std::cout << "__________________________________________________\n";
				DisplayEntityInformation();
				std::cout << "__________________________________________________\n";
				break;
			}
			case 6: {
				DisplayAllInformation();
				break;
			}
		}
	} while (choice!=7);
}

World::~World(){
	Entity* temp;
	while (!m_vEntity.empty()) {
		temp = m_vEntity.back();
		delete temp;
		m_vEntity.pop_back();
	}
}
