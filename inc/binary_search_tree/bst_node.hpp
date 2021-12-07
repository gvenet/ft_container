#ifndef BST_NODE
#define BST_NODE

namespace ft {

template <class T>
struct bst_node {
		typedef T					value_type;
		typedef bst_node* pointer;

		bst_node()
				: parent(), left(), right(), value(), is_limit( false ), left_depth(), right_depth() { }

		bst_node( pointer p, pointer l, pointer r, const value_type& val, bool b )
				: parent( p ), left( l ), right( r ), value( val ), is_limit( b ), left_depth(),
					right_depth() { }

		bst_node( const value_type& val, bool b )
				: parent(), left(), right(), value( val ), is_limit( b ), left_depth(), right_depth() { }

		pointer		 parent;
		pointer		 left;
		pointer		 right;
		value_type value;
		bool			 is_limit;
		int				 left_depth;
		int				 right_depth;
};

} // namespace ft
#endif