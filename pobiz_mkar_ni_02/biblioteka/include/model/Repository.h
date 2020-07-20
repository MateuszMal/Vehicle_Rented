//
// Created by student on 08.06.2020.
//

#ifndef MAL_LAT_REPOSITORY_H
#define MAL_LAT_REPOSITORY_H

#include <memory>
#include <list>

template <class T>
class Repository{
public:
    virtual ~Repository() = default;
    virtual void create(std::shared_ptr<T>&) = 0;
    virtual void remove(std::shared_ptr<T>&) = 0;
    virtual void remove(int index) = 0;
    virtual std::string getAll() = 0;
    virtual std::shared_ptr<T> find(int index) = 0;
    virtual bool find(std::shared_ptr<T>&) = 0;

};

#endif //MAL_LAT_REPOSITORY_H
