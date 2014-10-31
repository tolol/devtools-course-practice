// Copyright 2014 Anton Rybakov

#include <cstdlib>

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

template <typename _type> _tree_node<_type>::~_tree_node() {
    if (_next_brother != NULL)
        delete _next_brother;
    if (_first_child != NULL)
        delete _first_child;
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
    void add(_type value);
    bool destruct();
    _type get_value();
    unsigned int get_key();
    void down();
    void up();
    void along();
    void reset();
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

template <typename _type> bool _tree<_type>::destruct() {
    if (_current->get_child() != NULL)
        delete _current->get_child();
    _tree_node<_type>* temp = _current->get_parrent();
    temp = temp->get_child();
    if (temp == _current) {
        _current = temp->get_brother();
        temp->get_parrent()->set_child(_current);
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
        _current = temp;
    }
    return true;
}

template <typename _type> _type _tree<_type>::get_value() {
    return _current->get_value();
}

template <typename _type> unsigned int _tree<_type>::get_key() {
    return _current->get_key();
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
