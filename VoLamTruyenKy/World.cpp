#include "World.h"
#include<iostream>
World::World(){
}

void World::init(){
	Entity* EntHighestDamage = nullptr;
	unsigned int choice = 0;
	std::string Name;
	unsigned int cClass, cLevel, isBoss, cEle, indexA, indexB;
	do {
		std::cout << "=============================MENU=================================\n";
		std::cout << "1. Them nguoi choi vao danh sach.\n";
		std::cout << "2. Them quai vat vao danh sach.\n";
		std::cout << "3. Hien thi doi tuong co muc sat thuong cao nhat trong danh sach.\n";
		std::cout << "4. So sanh sat thuong giua hai doi tuong.\n";
		std::cout << "5. Xuat thong tin cua mot doi tuong.\n";
		std::cout << "6. Thoat tro choi.\n";
		std::cout << "==================================================================\n";
		std::cin >> choice;
		if (choice > 6 || choice < 1) {
			std::cout << "Vui long nhap lai lua chon.\n";
		}
		switch (choice) {
			case 1: {
				std::cout << "Nhap ten cua nhan vat:";
				std::cin.ignore();
				getline(std::cin, Name);
				std::cout << "Chon Bang Phai cho nhan vat.\n";
				std::cout << "0. Thieu Lam, 1. Thien Vuong Bang, 2. Ngu Doc Giao, 3. Duong Mon, 4. Nga My.\n";
				std::cout << "5. Thuy Yen Mon, 6. Cai Bang, 7. Thien Nhan Giao, 8. Con Lon, 9. Vo Dang.\n";
				std::cin >> cClass;
				std::cout << "Cap do cua nhan vat:";
				std::cin >> cLevel;
				m_vEntity.push_back(new Player{cLevel, (EClassID) cClass, Name});
				break;
			}
			case 2: {
				std::cout << "Nhap ten cua quai vat:";
				std::cin.ignore();
				getline(std::cin, Name);
				std::cout << "Cap do cua quai vat:";
				std::cin >> cLevel;
				std::cout << "Quai co phai la dau linh khong? (0. Khong, 1.Co):";
				std::cin >> isBoss;
				std::cout << "Hanh cua quai vat:\n(0.He Kim, 1. He Moc, 2. He Thuy, 3. He Hoa, 4. He Tho): ";
				std::cin >> cEle;
				m_vEntity.push_back(new Monster{ cLevel, (EElementsID)cEle, (bool)isBoss , Name});
				break;
			}
			case 3: {
				if (!m_vEntity.empty()) {
					for (unsigned int index = 0; index < m_vEntity.size(); ++index) {
						if (!EntHighestDamage || m_vEntity[index]->getBaseAttackDamage() > EntHighestDamage->getBaseAttackDamage()) {
							EntHighestDamage = m_vEntity[index];
						}
					}
					std::cout << "Doi tuong co muc sat thuong ban cao nhat.\n ";
					EntHighestDamage->info();
				}
				else {
					std::cout << "Danh sach chua co doi tuong nao.\n";
				}
				break;
			}
			case 4: {
				if (m_vEntity.size()>1) {
					std::cout << "Nhap thu tu cua 2 doi tuong can so sanh.\n";
					std::cout << "Vui long nhap thu tu hop le, khong nhap hai doi tuong trung nhau: ";
					do {
						std::cin >> indexA >> indexB;
					}while (indexA == indexB || indexA<0 || indexB<0 || indexA>m_vEntity.size() || indexB>m_vEntity.size());
					std::cout << "Sat thuong cua doi tuong thu " << indexA << " gay ra cho doi tuong thu " << indexB << " la:" << m_vEntity[indexA-1]->getDamageDealtTo(*m_vEntity[indexB-1]) <<'\n';
					std::cout << "Sat thuong cua doi tuong thu " << indexB << " gay ra cho doi tuong thu " << indexA << " la:" << m_vEntity[indexB-1]->getDamageDealtTo(*m_vEntity[indexA-1]) << '\n';
				}
				else {
					std::cout << "Danh sach phai co it nhat 2 doi tuong.\n";
				}
				break;
			}
			case 5: {
				if (!m_vEntity.empty()) {
					std::cout << "Nhap thu tu cua doi tuong can xuat thong tin:\n";
					std::cout << "Vui long nhap thu tu hop le:\n";
					do {
						std::cin >> indexA;
					} while (indexA<0 || indexA>m_vEntity.size());
					m_vEntity[indexA - 1]->info();
				}
				else {
					std::cout << "Danh sach chua co doi tuong nao.\n";
				}
				break;
			}
		}
	} while (choice!=6);
	EntHighestDamage = nullptr;
}

World::~World(){
	while (!m_vEntity.empty()) {
		Entity* temp = m_vEntity.back();
		delete temp;
		m_vEntity.pop_back();
	}
}
