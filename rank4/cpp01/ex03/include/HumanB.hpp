/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/13 13:54:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/14 01:16:38 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};

#endif
