#include "hash_list.h"

hash_list::hash_list() {

    head = nullptr;
    iter_ptr = nullptr;

}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {

    node *newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        size++;
    }
    else {
        node *curr = head;
        node *prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                delete newNode;
                curr->value = value;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        size++;
    }

}

std::optional<float> hash_list::get_value(int key) const { 
    
    node* curr = head;

    while (curr != nullptr) {
        if (curr->key == key) return curr->value; 
        curr = curr->next;
    }

    return std::nullopt; 
}

bool hash_list::remove(int key) { 

    if (head == nullptr) return false;

    node *curr = head;
    node *prev = nullptr;

    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return false;

    if (curr == head) head = curr->next;
    else prev->next = curr->next;
    delete curr;
    size--;

    return true; 
}

size_t hash_list::get_size() const {return size; }


hash_list::~hash_list() {
    node *curr = head;
    node *next;
    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/





/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
