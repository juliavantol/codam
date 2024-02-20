/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:04:39 by juvan-to      #+#    #+#                 */
/*   Updated: 2024/02/20 13:08:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &rhs);
		Dog & operator=(const Dog &rhs);
		void	makeSound(void) const;
};

#endif

