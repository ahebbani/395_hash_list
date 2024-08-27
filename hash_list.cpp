#include "hash_list.h"

hash_list::hash_list() {}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {

    /*
    
    node newnode = malloc(sizeof(node));
    newnode->key = key;
    newnode->value = value;

    while(head->next != null) {
        if(head->key == key && head->value == value) {
            return; // Use optional
        }
        head = head->next;
    }
    head->next = newnode;

    */

}

std::optional<float> hash_list::get_value(int key) const { return std::nullopt; }

bool hash_list::remove(int key) { 
    while (head->next->next != NULL) {
        if (head->next->key == key) {
            node temp = head->next->next;
            free(head->next);
            head->next = temp;
        }
        head = head->next;
    }
    return false; 
}

size_t hash_list::get_size() const { 
    int size = 0;
    while(head->next != NULL) {
        head = head->next;
        size++;
    }

    return 0; 
}

hash_list::~hash_list() {}

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
