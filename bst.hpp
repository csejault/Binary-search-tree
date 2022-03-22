/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:03 by csejault          #+#    #+#             */
/*   Updated: 2022/03/22 18:54:35 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//SOURCES :	Introduction to Algorithms : Thomas H. Cormen - Charles E. Leiserson - Ronald L. Rivest - Clifford Stein
//Class_Name = bst

//define{
#ifndef BST_HPP
# define BST_HPP

# ifndef COL_GREEN
#  define COL_GREEN 		"\033[0;32m"
# endif
# ifndef COL_RED
#  define COL_RED		"\033[0;31m"
# endif
# ifndef COL_YELLOW
#  define COL_YELLOW		"\033[0;33m"
# endif
# ifndef COL_NORMAL
#  define COL_NORMAL		"\033[0m"
# endif

# include <iostream>
//define - END}

template < typename T >
class	bst {

	public:
		enum	position
		{
			LEFT = 0,
			RIGHT
		};
		typedef bst<T> 		node;
		typedef node*		p_node;
		typedef p_node*		tree;
		typedef T			value_type;
		typedef T*			pointer;
		typedef T&			reference;

		//pub_constructor{
		bst( p_node n, value_type k) : p(n), left(NULL), right(NULL), key(k)   {}
		~bst( void ) {
			if (left)
				delete left;
			if (right)
				delete right;
		}
		//pub_constructor - END}

		//pub_operator{
		//pub_operator - END}

		//pub_debug{
		//pub_debug - END}

		//pub_static{

		static p_node	minimum(p_node n)
		{
			while (n->left)
				n = n->left;
			return (n);
		}

		static p_node	maximum(p_node n)
		{
			while (n->right)
				n = n->right;
			return (n);
		}

		static p_node predecessor(p_node n)
		{
			p_node s = NULL;
			if (n->left)
				return (minimum(n->left));
			s = n->p;
			while(s && n == s->left)
			{
				n = s;
				s = s->p;
			}
			return (s);
		}

		static p_node successor(p_node n)
		{
			p_node s = NULL;
			if (n->right)
				return (minimum(n->right));
			s = n->p;
			while(s && n == s->right)
			{
				n = s;
				s = s->p;
			}
			return (s);
		}

		static p_node search(p_node n, value_type k)
		{
			if (!n || n->key == k)
				return (n);
			if (k < n->key)
				return (search(n->left, k));
			else
				return (search(n->right, k));
		}

		static p_node	iterative_search(p_node n, value_type k)
		{
			while (n && k != n->key)
			{
				if (k < n->key)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}

		static void	inorder_walk( p_node p ) {
			if (p)
			{
				inorder_walk(p->left);
				p->print_key();
				inorder_walk(p->right);
			}
		}

		static void	t_insert(tree t, p_node n)
		{
			p_node y = NULL;
			p_node x = *t;
			while (x)
			{
				y = x;
				if (n->key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			n->p = y;
			if (!y)
				*t = n;
			else if (n->key < y->key)
				y->left = n;
			else
				y->right = n;
		}

		static void transplant(tree t, p_node u, p_node v)
		{
			if (!u->p)
				*t = v;
			else if (u == u->p->left)
				u->p->left = v;
			else
				u->p->right = v;
			if (v)
				v->p = u->p;
		}

		static void	t_delete(tree t, p_node z)
		{
			if (!z->left)
				node::transplant(t,z,z->right);
			else if (!z->right)
				node::transplant(t,z,z->left);
			else
			{
				p_node y = node::minimum(z->right);
				if (y->p != z)
				{
					node::transplant(t,y,y->right);
					y->right = z->right;
					y->right->p = y;
				}
					node::transplant(t,z,y);
					y->left = z->left;
					y->left->p = y;
			}
		}
		//pub_static - END}

		//pub_getter{
		//pub_getter - END}

		//pub_setter{
		//pub_setter - END}

		//pub_exception{
		//pub_exception - END}

		//pub_fct{
		void	print_key( void ) {
			std::cout << key << std::endl;
		}
		//pub_fct - END}

		//pub_var{
		p_node		p;
		p_node		left;
		p_node		right;
		value_type	key;
		//pub_var - END}

	private:
		//priv_debug{
		//priv_debug - END}

		//priv_constructor{
		bst( void ) {};
		//priv_constructor - END}

		//priv_static{
		//priv_static - END}

		//priv_var{
		//priv_var - END}
};

//out_class{
//std::ostream &	operator<<(std::ostream &os, bst &to_print);
//out_class - END}

#endif

//Color{
//The codes for foreground and background colours are:
//
//         foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47
//Color - END}
