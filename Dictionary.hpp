#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

template <typename Key, typename Val>
class Dictionary {
    public:
        // default constructor
        Dictionary() { }

        // destructor
        virtual ~Dictionary() { }

        // remove all records in the dictionary
        virtual void clear() = 0;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const = 0;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) = 0;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) = 0;

        // return the number of records in the dictionary
        virtual int size() const = 0;

        // sort the records in the dictionary using the algorithm (argument 1)
        virtual void sort(int) = 0;
};

#endif
