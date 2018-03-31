#ifndef ComphepSingletopFilterPy8_h
#define ComphepSingletopFilterPy8_h


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "FWCore/Framework/interface/global/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

//
// class declaration
//
namespace edm {
  class HepMCProduct;
}

class ComphepSingletopFilterPy8 : public edm::global::EDFilter<> {
public:
    explicit ComphepSingletopFilterPy8(const edm::ParameterSet&);
    ~ComphepSingletopFilterPy8() override;
private:
    void beginJob() override ;
    
    bool filter(edm::StreamID, edm::Event&, const edm::EventSetup&) const override;
    void endJob() override ;
    edm::EDGetTokenT<edm::HepMCProduct> token_;
private:
    double _ptsep;
    int _read22, _read23, _pass22, _pass23, _hardLep;
};

#endif
