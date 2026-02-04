class RideSharingSystem {
public:
    vector<int> driver;
    vector<int> rider;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size() > 0 && driver.size() > 0) {
            int r = rider[0];
            int d = driver[0];
            rider.erase(rider.begin());
            driver.erase(driver.begin());
            return {d, r};
        }
        return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        if(find(rider.begin(), rider.end(), riderId) != rider.end()) {
            rider.erase(find(rider.begin(), rider.end(), riderId));
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */