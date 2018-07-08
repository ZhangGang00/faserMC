#ifndef INCLUDE_ROOTEVENTIO_HH
#define INCLUDE_ROOTEVENTIO_HH 1

#include "G4String.hh"

class FaserGeometry;
class FaserEvent;
class TFile;
class TTree;

class RootEventIO
{
public:
  virtual ~RootEventIO();

  static RootEventIO* GetInstance();
  static void SetFileName(G4String name);
  void Write(FaserEvent*);
  void Write(FaserGeometry*);
  void Close();

protected:
  RootEventIO();

private:
  TFile* fFile;
  TTree* fTree;
  TTree* fGeoTree;
  int fNevents;
  FaserEvent* fBranchAdx;
  FaserGeometry* fGeoBranchAdx;
};

#endif
