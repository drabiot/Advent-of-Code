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

password::password(int size) : _dial(nullptr), _tail(nullptr) {
	for (int i = 0; i <= size; ++i) {
		append(i);
	}

    if (_dial)
    {
        _dial->prev = _tail;
        _tail->next = _dial;
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

}
