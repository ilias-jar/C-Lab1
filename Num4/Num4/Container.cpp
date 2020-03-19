#include "Container.h"
#include <algorithm>

int MinMax;

double Max, Last;
int RandomNumber() {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (2 * MinMax + 1) - MinMax);
}

std::ifstream& Container::GenerateRandomFileLoop(const std::string fileName, const int M, const int count) const {
	std::ofstream File(fileName, std::ios::out);

	MinMax = M;

	for (int i = 0; i < count; i++) {
		int num = RandomNumber();
		File << num << ' ';
	}

	File.close();

	std::ifstream* Result = new std::ifstream(fileName);

	return *Result;
}

std::ifstream& Container::GenerateRandomFile(const std::string fileName, const int M, const int count) const {
	std::ofstream File(fileName, std::ios::out);

	std::list<double> tmpList(count);

	MinMax = M;

	std::generate(tmpList.begin(), tmpList.end(), RandomNumber);

	for (double num : tmpList) {
		File << num << ' ';
	}

	File.close();

	std::ifstream* Result = new std::ifstream(fileName);

	return *Result;
}

std::list<double>* Container::FillListFromFile(std::ifstream &file) const{
	std::list<double>* tmpList = new std::list<double>;

	if (file.is_open()){
		while (!file.eof()) {
			double num;
			file >> num;
			(*tmpList).push_back(num);
		}
		file.clear(); 
		file.seekg(0, std::ios::beg);
	}
	else {
		std::cout << "Ошибка чтения файла";
	}

	return tmpList;
}

double FindMax(const std::list<double> List) {
	double max = List.front();
	for (double el : List) {
		if (el > max)
			max = el;
	}
	return max;
}

std::list<double>* Container::ModifyContainer(std::list<double>& originList){
	double last = originList.back();
	double max = FindMax(originList);

	std::list<double>* result = new std::list<double>;

	for (double el : originList) {
		(*result).push_back(el + sqrt(abs(max * last)));
	}

	return result;
}

std::list<double>* Container::ModifyContainer(std::list<double>& originList,
	std::list<double>::iterator& begin,
	std::list<double>::iterator& end){

	double last = originList.back();
	double max = FindMax(originList);

	std::list<double>* result = new std::list<double>;

	(*result).resize(originList.size());

	for (auto iter = begin; iter != end; iter++)
		*iter += sqrt(abs(max * last));

	for (auto iter = originList.begin(); iter != originList.end(); iter++)
		(*result).push_back(*iter);

	return result;
}

double Modify(double el) {
	return el + sqrt(abs(Max * Last));
}

std::list<double>* Container::ModifyContainerTransform(std::list<double>& originList){
	Last = originList.back();
	Max = FindMax(originList);

	std::list<double>* result = new std::list<double>;

	(*result).resize(originList.size());

	std::transform(originList.begin(), originList.end(), (*result).begin(), Modify);

	return result;
}

std::list<double>* Container::ModifyContainerFor_Each(std::list<double>& originList,
	std::list<double>::iterator& begin,
	std::list<double>::iterator& end){

	Last = originList.back();
	Max = FindMax(originList);

	std::list<double>* result = new std::list<double>;

	std::for_each(begin, end, [](double& num) { num += sqrt(abs(Max * Last)); });

	for (auto iter = originList.begin(); iter != originList.end(); iter++) {
		(*result).push_back(*iter);
	}

	return result;
}

double Container::Sum(const std::list<double>& List) const{
	double result = 0;

	for (double el : List)
		result += el;

	return result;
}

double Container::MidArifm(const std::list<double>& List) const{
	double sum = Sum(List);
	int count = List.size();

	return (double)sum / count;
}

void print(const std::list<double>& List, std::ostream& out) {
	for (double el : List) {
		out << el << ' ';
	}
	system("pause");
}

void Container::Print(std::string fileName) const {
	if (fileName == "") {
		print(*l_curr, std::cout);
	}
	else {
		std::ofstream File(fileName, std::ios::out);
		print(*l_curr, File);
		File.close();
	}

}