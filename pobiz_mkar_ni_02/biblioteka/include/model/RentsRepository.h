#ifndef MAL_LAT_RENTSREPOSITORY_H
#define MAL_LAT_RENTSREPOSITORY_H

#include "Rent.h"
#include "Repository.h"
#include <vector>
#include <memory>

class Vehicle;

class RentsRepository : Repository<Rent>{
private:
    std::list<RentPtr> currentRents;
    std::list<RentPtr> archiveRents;
public:
    RentsRepository();
    void create(RentPtr&) override ;
    void remove(RentPtr&) override ;
    void rentReport();
    void remove(int index) override;
    std::string getAll() override;
    shared_ptr<Rent> find(int index) override;
    bool find(shared_ptr<Rent> &ptr) override;
    const list<RentPtr> &getCurrentRents() const;
    const list<RentPtr> &getArchiveRents() const;
    virtual ~RentsRepository() override ;
};

typedef shared_ptr<RentsRepository> RentsRepositoryPtr;

#endif //MAL_LAT_RENTSREPOSITORY_H
