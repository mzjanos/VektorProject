#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <atlstr.h>
#include <algorithm>

#include "m_vector.h"
#ifndef LOGIC_H
#define LOGIC_H


template <typename T>
class vectors_compare_x {
public:
	vectors_compare_x() {}
	bool operator()(typename const m_vector<T>& a, typename const m_vector<T>& b) {
		return a.getX() < b.getX();
	}
};

template <typename T>
bool read_vectors_from_file(const std::string& path, std::vector<m_vector<T>>& file_content, CString& message) {
	std::ifstream file;
	std::string line;;
	file_content.clear();
	file.open(path);
	if(!file.is_open()){
		CString m("A fájl nem nyilt meg");
		message = m;
		return false;
	}
	T coordinates[3];
	int c = 0;
	while (std::getline(file, line)) {
		std::stringstream s(line);
		std::string point;
		int component_count = 0;
		while (std::getline(s, point, ';')) {
			if (component_count >= 3) {
				message = ErrorMessageAndClear("Hibas text formatum a fajlban", file_content);
				return false;
			}
			try {
				coordinates[component_count] = m_parse_from_string<T>(point);
			}
			catch(std::exception){
				message = ErrorMessageAndClear("Hibas text formatum a fajlban", file_content);
				return false;
			}
			++component_count;
		}
		if (component_count != 3) {
			message = ErrorMessageAndClear("Hibas text formatum a fajlban", file_content);
			return false;
		}
		m_vector<T> p(coordinates[0], coordinates[1], coordinates[2]);
		file_content.push_back(p);
	}
	file.close();
	return true;
}

template<typename T> 
CString ErrorMessageAndClear(const char* str, std::vector<m_vector<T>>& to_clear) {
	CString m(str);
	to_clear.clear();
	return m;
}

template<typename T>
void create_vectors(std::vector<m_vector<T>>& points, std::vector<m_vector<T>>& vectors) {
	std::vector<m_vector<T>> temp;
	for(int i = 0; i + 1 < points.size(); i += 2) {
		temp.push_back(points[i + 1] - points[i]);
	}
	vectors = temp;
}

template<typename T>
void project_and_sort(std::vector<m_vector<T>>& data) {
	for (int i = 0; i < data.size(); i++) {
		data[i].setZ(0);
	}
	std::sort(data.begin(), data.end(), vectors_compare_x<T>());
}

template<typename T>
bool write_to_file(const std::string& path, const std::vector<m_vector<T>>& file_content){
	std::ofstream file;
	file.open(path);
	if (!file.is_open()) {
		return false;
	}
	typename std::vector<m_vector<T>>::const_iterator it = file_content.cbegin();
	while (it != file_content.end()) {
		file << it->getX() << ";" << it->getY() << "\n";
		++it;
	}
	file.close();
	return true;
}

template <typename T>
T m_parse_from_string(const std::string& input) {

}
template <>
inline int m_parse_from_string(const std::string& input) {
	return std::stoi(input);
}
template <>
inline double m_parse_from_string(const std::string& input) {
	return std::stod(input);
}

bool check_input(const std::string&);

#endif
