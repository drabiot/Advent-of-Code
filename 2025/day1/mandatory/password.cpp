/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:01:59 by tchartie          #+#    #+#             */
/*   Updated: 2025/12/01 13:01:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password.hpp"

password::password(int size) : _dial(nullptr), _tail(nullptr), _current(nullptr) {
	this->_password = 0;

	for (int i = 0; i <= size; ++i) {
		append(i);
	}

    if (_dial)
    {
        _dial->prev = _tail;
        _tail->next = _dial;
		_current = _dial;
		for (int j = 0; j < 50; ++j)
			_current = _current->next;
    }
}

password::~password() {
	if (!_dial)
		return;

	_tail->next = nullptr;
	_dial->prev = nullptr;

	Node<int>* current = _dial;
	while (current)
	{
		Node<int>* next = current->next;
		delete current;
		current = next;
	}
}

void	password::append(int value) {
	Node<int>* node = new Node<int>();
	node->data = value;

	if (!_dial) {
		_dial = node;
		_tail = node;
	}
	else {
		_tail->next = node;
		node->prev = _tail;
		_tail = node;
	}

}

void	password::readInput(str filename) {
	std::ifstream	file(filename);
	str				line;

	if (!file.is_open())
		throw std::runtime_error("Can't open file");

	while (std::getline(file, line)) {
		if (!line.empty() && line.back() == '\r')
			line.pop_back();

		if (line.empty())
            continue;

		_input.push_back(line);
	}

}

void	password::useInput(void) {
	for (size_t i = 0; i < _input.size(); ++i) {
		bool	dir;							//True = left / False = right
		int		rotation;						//Number of rotation to do

		str		firstInput = _input[i].substr(0, 1);
		str		lastInput  = _input[i].substr(1);

		if (firstInput == "L")
			dir = true;
		else
			dir = false;

		rotation = atoi(lastInput.c_str());

		for (int i = 0; i < rotation; ++i) {
			if (dir)
				_current = _current->prev;
			else
				_current = _current->next;
		}

		if (_current->data == 0)
			this->_password++;
	}
}

int		password::getPassword(void) {
	return (this->_password);
}
