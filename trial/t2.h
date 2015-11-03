//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 22 15:20:51 2015 by ROOT version 6.02/05
// from TTree t1/analtree
// found on file: tryfile.root
//////////////////////////////////////////////////////////

#ifndef t2_h
#define t2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
#include "TTree.h"
#include <iostream>
//#include "frclass.h"
using namespace std;
class frclass;
class t2 {
  //friend class frclass;
public :
  
  frclass* frobj;
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
// private:
   // Declaration of leaf types
   std::vector<float>   *p2;
   std::vector<float>   *p3;
    void  p4(){std::cout<<" working "<<std::endl;};

   
   // List of branches
   TBranch        *b_p2;   //!
   TBranch        *b_p3;   //!

   t2(TTree *tree=0);
   virtual ~t2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef t2_cxx
t2::t2(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("tryfile.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("tryfile.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

t2::~t2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t t2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t t2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void t2::Init(TTree *tree)
{
  // Set object pointer
   p2 = 0;
   p3 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("p2", &p2, &b_p2);
   fChain->SetBranchAddress("p3", &p3, &b_p3);
   Notify();
}

Bool_t t2::Notify()
{
  return kTRUE;
}

void t2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t t2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef t2_cxx
