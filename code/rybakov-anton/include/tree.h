// Copyright 2014 Anton Rybakov

#include <cstdlib>
#include <string>

#ifndef CODE_RYBAKOV_ANTON_INCLUDE_TREE_H_
#define CODE_RYBAKOV_ANTON_INCLUDE_TREE_H_

// Tree node template implementation

template <typename _type> struct _tree_search {
    bool success;
    _type value;
    unsigned int key;
};

template <typename _type> class _tree_node {
 private:
    unsigned int _key;
    _type _value;
    _tree_node* _first_child;
    _tree_node* _next_brother;
    _tree_node* _parrent;
 public:
    _tree_node(_type value, _tree_node<_type>* parrent, unsigned int key);
    _tree_node(const _tree_node<_type> &src, _tree_node<_type> *p);
    ~_tree_node();
    _type get_value();
    unsigned int get_key();
    _tree_node* get_child();
    void set_child(_tree_node* node);
    _tree_node* get_brother();
    void set_brother(_tree_node* node);
    _tree_node* get_parrent();
};

template <typename _type> _tree_node<_type>::_tree_node
(_type value, _tree_node<_type>* parrent, unsigned int key) {
      _value = value;
      _parrent = parrent;
      _first_child = NULL;
      _next_brother = NULL;
      _key = key;
}

template <typename _type>
_tree_node<_type>::_tree_node
(const _tree_node<_type> &src, _tree_node<_type> *p = NULL) {
    _key = src._key;
    _value = src._value;
    _parrent = p;
    if (src._first_child != NULL) {
        _first_child = new _tree_node<_type>(*src._first_child, this);
    } else {
        _first_child = NULL;
    }
    if (src._next_brother != NULL) {
        _next_brother = new _tree_node<_type>(*src._next_brother, p);
    } else {
        _next_brother = NULL;
    }
}

template <typename _type> _tree_node<_type>::~_tree_node() {
    if (_next_brother != NULL) {
        delete _next_brother;
        _next_brother = NULL;
    }
    if (_first_child != NULL) {
        delete _first_child;
        _first_child = NULL;
    }
}

template <typename _type> _type _tree_node<_type>::get_value() {
    return _value;
}

template <typename _type> unsigned int _tree_node<_type>::get_key() {
    return _key;
}

template <typename _type> _tree_node<_type>* _tree_node<_type>::get_child() {
    return _first_child;
}

template <typename _type> void _tree_node<_type>::set_child(_tree_node* node) {
    _first_child = node;
}

template <typename _type> _tree_node<_type>* _tree_node<_type>::get_brother() {
    return _next_brother;
}

template <typename _type>
void _tree_node<_type>::set_brother(_tree_node* node) {
    _next_brother = node;
}

template <typename _type> _tree_node<_type>* _tree_node<_type>::get_parrent() {
    return _parrent;
}

// Tree template implementation

template <typename _type> class _tree {
 private:
    unsigned int _key_counter;
    _tree_node<_type>* _root;
    _tree_node<_type>* _current;
 public:
    _tree();
    ~_tree();
    _tree(const _tree<_type>& src);
    _tree<_type>& operator=(const _tree<_type>& src);
    void add(_type value);
    void destruct();
    _type get_value();
    unsigned int get_key();
    void down();
    void up();
    void along();
    void reset();
    bool is_empty();
    _tree_search<_type> search(unsigned int key);
};

template <typename _type> _tree<_type>::_tree() {
    _key_counter = 0;
    _root = NULL;
    _current = NULL;
}

template <typename _type> _tree<_type>::~_tree() {
    if (_root != NULL)
        delete _root;
}

template <typename _type> _tree<_type>::_tree(const _tree<_type> & src) {
    _key_counter = src._key_counter;
    _root = new _tree_node<_type>(*src._root);
    _current = _root;
}

template <typename _type>
_tree<_type>& _tree<_type>::operator=(const _tree<_type>& src) {
    if (_root != NULL)
        delete _root;
    _key_counter = src._key_counter;
    _root = new _tree_node<_type>(*src._root);
    _current = _root;
    return *this;
}

template <typename _type> void _tree<_type>::add(_type value) {
    _tree_node<_type>*
        adding = new _tree_node<_type>(value, _current, _key_counter);
    if (_root == NULL) {
        _root = adding;
        _current = _root;
    } else {
        _tree_node<_type>* current_child = _current->get_child();
        if (current_child == NULL) {
            _current->set_child(adding);
        } else {
            while (current_child->get_brother() != NULL)
                current_child = current_child->get_brother();
            current_child->set_brother(adding);
        }
    }
    _key_counter++;
}

template <typename _type> void _tree<_type>::destruct() {
    if (_root == NULL) {
        throw std::string("Tree is empty");
    } else {
        if (_current->get_child() != NULL) {
            delete _current->get_child();
            _current->set_child(NULL);
        }
        if (_current == _root) {
            delete _root;
            _root = NULL;
            _current = NULL;
        } else {
            _tree_node<_type>* temp = _current->get_parrent();
            temp = temp->get_child();
            if (temp == _current) {
                _current = temp->get_parrent();
                temp->get_parrent()->set_child(temp->get_brother());
                temp->set_brother(NULL);
                temp->set_child(NULL);
                delete temp;
            } else {
                while (temp->get_brother()->get_key() != _current->get_key())
                    temp = temp->get_brother();
                temp->set_brother(_current->get_brother());
                _current->set_brother(NULL);
                _current->set_child(NULL);
                delete _current;
                _current = temp->get_parrent();
            }
        }
    }
}

template <typename _type> _type _tree<_type>::get_value() {
    if (_current != NULL)
        return _current->get_value();
    else
        throw std::string("Tree is empty");
}

template <typename _type> unsigned int _tree<_type>::get_key() {
    if (_current != NULL)
        return _current->get_key();
    else
        throw std::string("Tree is empty");
}

template <typename _type> bool _tree<_type>::is_empty() {
    if (_current == NULL && _root == NULL)
        return true;
    else
        return false;
}

template <typename _type> void _tree<_type>::up() {
    if (_current != _root)
        _current = _current->get_parrent();
}

template <typename _type> void _tree<_type>::down() {
    if (_current->get_child() != NULL)
        _current = _current->get_child();
}

template <typename _type> void _tree<_type>::along() {
    if (_current->get_brother() != NULL)
        _current = _current->get_brother();
}

template <typename _type> void _tree<_type>::reset() {
    _current = _root;
}

template <typename _type>
_tree_search<_type> _tree<_type>::search(unsigned int key) {
    _tree_search<_type> result;
    if (_root == NULL) {
        result.success = false;
        return result;
    }
    _tree_node<_type>* temp = _root;
    do {
        if (temp->get_key() == key) {
            result.success = true;
            result.value = temp->get_value();
            result.key = temp->get_key();
            return result;
        }
        if (temp->get_child() != NULL) {
            temp = temp->get_child();
            continue;
        }
        if (temp->get_brother() != NULL) {
            temp = temp->get_brother();
            continue;
        }
        while (temp != NULL) {
            if (temp->get_brother() == NULL) {
                temp = temp->get_parrent();
            } else {
                temp = temp->get_brother();
                break;
            }
        }
    } while (temp != NULL);
    result.success = false;
    return result;
}

#endif  // CODE_RYBAKOV_ANTON_INCLUDE_TREE_H_
