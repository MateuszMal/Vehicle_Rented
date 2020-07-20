//
// Created by student on 12.06.2020.
//

#ifndef MAL_LAT_PREDICATETEMPLATE_H
#define MAL_LAT_PREDICATETEMPLATE_H

template <class T>
        class PredicateTemplate{
private:
    T search;
public:
    PredicateTemplate(T search) : search(search){};

    bool operator () (const T &check){
        return search == check;
    }
};

#endif //MAL_LAT_PREDICATETEMPLATE_H
