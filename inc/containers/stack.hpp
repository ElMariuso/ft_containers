/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:50 by root              #+#    #+#             */
/*   Updated: 2022/12/13 21:11:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

/* Includes ***************************************************************** */

# include <iostream>

/* Includes.h *************************************************************** */

# include "../containers/vector.hpp"

/* Class ******************************************************************** */

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        /* Member types ************************************************************* */
        public:
            typedef Container                                   container_type;
            typedef typename container_type::value_type         value_type;
            typedef typename container_type::size_type          size_type;
            typedef typename container_type::reference          reference;
            typedef typename container_type::const_reference    const_reference;

        /* Attributes *************************************************************** */
        protected:
            container_type  c;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        explicit stack(const container_type& ctnr = container_type()): c(ctnr) {}

        /* Destructor */
        ~stack() {}

        /* operator= */
        stack& operator=(const stack& x)
        {
            this->c = x.c;
            return (*this);
        }

        /***** Element access *****/
        /* top */
        reference top() { return (this->c.back()); }
        const_reference top() const { return (this->c.back()); }
        
        /***** Capacity *****/
        /* empty */
        bool empty() const { return (this->c.empty()); }

        /* size */
        size_type   size() const { return (this->c.size()); }

        /***** Modifiers *****/
        /* push */
        void    push(const value_type& value) { this->c.push_back(value); }

        /* pop */
        void    pop() { this->c.pop_back(); }

        /***** Friend *****/
        template <class TF, class ContainerF>
        friend bool    operator==(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);
        template <class TF, class ContainerF>
        friend bool    operator!=(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);
        template <class TF, class ContainerF>
        friend bool    operator<(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);
        template <class TF, class ContainerF>
        friend bool    operator<=(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);
        template <class TF, class ContainerF>
        friend bool    operator>(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);
        template <class TF, class ContainerF>
        friend bool    operator>=(ft::stack<TF, ContainerF>& lhs, ft::stack<TF, ContainerF>& rhs);

        /***** Utils Functions *****/
        private:
    };
    /* Non-member function overloads ******************************************** */
    /* relational operators */
    template <class T, class Container>
    bool    operator==(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool    operator!=(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c != rhs.c);  
    }

    template <class T, class Container>
    bool    operator<(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool    operator<=(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c <= rhs.c);
    }

    template <class T, class Container>
    bool    operator>(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool    operator>=(ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs)
    {
        return (lhs.c >= rhs.c);
    }
}

#endif