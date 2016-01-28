{

  // TFile *f1 = new TFile("Pileup_DYJetsToLL_M-50.root","READ");
  //TFile *f2 = new TFile("Pileup_ElectronData.root","READ");



  TFile *f1 = new TFile("MCPU_trueInt.root","READ");
  TFile *f2 = new TFile("DataPU_69p3mb.root","READ");

  //TFile *f1 = new TFile("Pileup_DYJetsToLL_M-25.root","READ");
  //TFile *f2 = new TFile(" Data_25ns.root","READ");
 TH1F *h1;
 TH1F *h2;
 TH1F *h3;  
 
 //  h1 = (TH1F*) f1->Get("mcPUDist");
 h1 = (TH1F*) f1->Get("pileup");
 //h2 = (TH1F*) f2->Get("Pileup_data");
 h2 = (TH1F*) f2->Get("pileup");
 h3 = (TH1F*) h2->Clone("PileUpweighted");
 
 h1->SetName("MC");
 h2->SetName("Data");

 // h1->Scale(1./h1->Integral());
 // h3->Scale(1./h3->Integral());
 // h2->Scale(1./h2->Integral());

 int nbins = h1->GetNbinsX();
 int xmin = h1->GetXaxis()->GetXmin();
 int xmax = h1->GetXaxis()->GetXmax();

 cout <<"Nbins:  " << nbins << "  xmin : " << xmin << "  xmax : " << xmax <<std::endl;

 for(int i = xmin; i < xmax; i++){

   if(h1->GetBinContent(i+1) > 0.){
     h3->SetBinContent(i+1, h2->GetBinContent(i+1)/h1->GetBinContent(i+1));}
   else{ h3->SetBinContent(i+1,1);}


   cout  << i+1 << "  " <<h2->GetBinContent(i+1) << "   " <<h1->GetBinContent(i+1)  <<"   "<< h3->GetBinContent(i+1) <<std::endl;


 }
 



 // h3->Divide(h1);

 
 TFile *f3 = new TFile("PileUpWeightedFile_true69p3mb.root","RECREATE");
 f3->cd();
 h1->Write();
 h2->Write();
 h3->Write();
 
 f3->Close();


}
