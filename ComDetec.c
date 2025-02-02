void code()
{
auto *myfile1 = TFile::Open("v1.root");
auto *myfile2 = TFile::Open("v2.root");
auto *myfile3 = TFile::Open("v4.root");

auto mytree1 = myfile1->Get<TTree>("Scoring");
auto mytree2 = myfile2->Get<TTree>("Scoring");
auto mytree3 = myfile3->Get<TTree>("Scoring");

double Edep1,Xgen1,Ygen1,Zgen1,pmt01,pmt11,pmt21;
double Edep2,Xgen2,Ygen2,Zgen2,pmt02,pmt12,pmt22;
double Edep3,Xgen3,Ygen3,Zgen3,pmt03,pmt13,pmt23;

mytree1->SetBranchAddress("c0fEdep", &Edep1);
mytree1->SetBranchAddress("c1Xgen", &Xgen1);
mytree1->SetBranchAddress("c2Ygen", &Ygen1);
mytree1->SetBranchAddress("c3Zgen", &Zgen1);
mytree1->SetBranchAddress("c4PMT0SC", &pmt01);
mytree1->SetBranchAddress("c5PMT1SC", &pmt11);
mytree1->SetBranchAddress("c6PMT2SC", &pmt21);


mytree2->SetBranchAddress("c0fEdep", &Edep2);
mytree2->SetBranchAddress("c1Xgen", &Xgen2);
mytree2->SetBranchAddress("c2Ygen", &Ygen2);
mytree2->SetBranchAddress("c3Zgen", &Zgen2);
mytree2->SetBranchAddress("c4PMT0SC", &pmt02);
mytree2->SetBranchAddress("c5PMT0SC", &pmt12);
mytree2->SetBranchAddress("c6PMT0SC", &pmt22);

mytree3->SetBranchAddress("c0fEdep", &Edep3);
mytree3->SetBranchAddress("c1Xgen", &Xgen3);
mytree3->SetBranchAddress("c2Ygen", &Ygen3);
mytree3->SetBranchAddress("c3Zgen", &Zgen3);
mytree3->SetBranchAddress("c4PMT0SC", &pmt03);
mytree3->SetBranchAddress("c5PMT0SC", &pmt13);
mytree3->SetBranchAddress("c6PMT0SC", &pmt23);

TH1D *h1e = new TH1D("h1e","c0fEdep from v1",50,0,1);
TH1D *h2e = new TH1D("h2e","c0fEdep from v2",50,0,1);
TH1D *h3e = new TH1D("h3e","c0fEdep from v4",50,0,1);

TH1D *h1x = new TH1D("h1x","c1Xgen from v1",50,-5,5);
TH1D *h2x = new TH1D("h2x","c1Xgen from v2",50,-5,5);
TH1D *h3x = new TH1D("h3x","c1Xgen from v4",50,-5,5);

TH1D *h1y = new TH1D("h1y","c2Ygen from v1",50,-5,5);
TH1D *h2y = new TH1D("h2y","c2Ygen from v2",50,-5,5);
TH1D *h3y = new TH1D("h3y","c2Ygen from v4",50,-5,5);

TH1D *h1z = new TH1D("h1z","c3Zgen from v1",50,-5,10);
TH1D *h2z = new TH1D("h2z","c3Zgen from v2",50,-5,10);
TH1D *h3z = new TH1D("h3z","c3Zgen from v4",50,-5,10);

TH1D *h1p1 = new TH1D("h1p1","c4PMT0SC from v1",40,0,40);
TH1D *h2p1 = new TH1D("h2p1","c4PMT0SC from v2",40,0,40);
TH1D *h3p1 = new TH1D("h3p1","c4PMT0SC from v4",40,0,40);

TH1D *h1p2 = new TH1D("h1p2","c5PMT1SC from v1",50,0,50);
TH1D *h2p2 = new TH1D("h2p2","c5PMT1SC from v2",50,0,50);
TH1D *h3p2 = new TH1D("h3p2","c5PMT1SC from v4",50,0,50);

TH1D *h1p3 = new TH1D("h1p3","c6PMT2SC from v1",30,0,30);
TH1D *h2p3 = new TH1D("h2p3","c6PMT2SC from v2",30,0,30);
TH1D *h3p3 = new TH1D("h3p3","c6PMT2SC from v4",30,0,30);


auto hstack1 =new THStack("stack1","Edep");
auto hstack2 =new THStack("stack2","Xgen");
auto hstack3 =new THStack("stack3","Ygen");
auto hstack4 =new THStack("stack4","Zgen");
auto hstack5 =new THStack("stack5","PMT1");
auto hstack6 =new THStack("stack6","PMT2");
auto hstack7 =new THStack("stack7","PMT3");

int mytree1entry=mytree1->GetEntries();
int mytree2entry=mytree2->GetEntries();
int mytree3entry=mytree3->GetEntries();

//cout<<"mytree1entry="<<mytree1entry<<endl;

for (int iEntry = 0; iEntry<mytree1entry; ++iEntry) 
{
   mytree1->GetEntry(iEntry);  
   
   h1e->Fill(Edep1);
   h1x->Fill(Xgen1);
   h1y->Fill(Ygen1);
   h1z->Fill(Zgen1);
   h1p1->Fill(pmt01);
   h1p2->Fill(pmt11);
   h1p3->Fill(pmt21);
}

h1e->SetFillColor(kRed);
h1x->SetFillColor(kRed);
h1y->SetFillColor(kRed);
h1z->SetFillColor(kRed);
h1p1->SetFillColor(kRed);
h1p2->SetFillColor(kRed);
h1p3->SetFillColor(kRed);

hstack1->Add(h1e);
hstack2->Add(h1x);
hstack3->Add(h1y);
hstack4->Add(h1z);
hstack5->Add(h1p1);
hstack6->Add(h1p2);
hstack7->Add(h1p3);

for (int iEntry = 0; iEntry<mytree2entry; ++iEntry) 
{
   mytree2->GetEntry(iEntry);  
   
   h2e->Fill(Edep2);
   h2x->Fill(Xgen2);
   h2y->Fill(Ygen2);
   h2z->Fill(Zgen2);
   h2p1->Fill(pmt02);
   h2p2->Fill(pmt12);
   h2p3->Fill(pmt22);
}

h2e->SetFillColor(kBlue);
h2x->SetFillColor(kBlue);
h2y->SetFillColor(kBlue);
h2z->SetFillColor(kBlue);
h2p1->SetFillColor(kBlue);
h2p2->SetFillColor(kBlue);
h2p3->SetFillColor(kBlue);

hstack1->Add(h2e);
hstack2->Add(h2x);
hstack3->Add(h2y);
hstack4->Add(h2z);
hstack5->Add(h2p1);
hstack6->Add(h2p2);
hstack7->Add(h2p3);


for (int iEntry = 0; iEntry<mytree3entry; ++iEntry) 
{
   mytree3->GetEntry(iEntry);  
   
   h3e->Fill(Edep3);
   h3x->Fill(Xgen3);
   h3y->Fill(Ygen3);
   h3z->Fill(Zgen3);
   h3p1->Fill(pmt03);
   h3p2->Fill(pmt13);
   h3p3->Fill(pmt23);
}


h3e->SetFillColor(kGreen);
h3x->SetFillColor(kGreen);
h3y->SetFillColor(kGreen);
h3z->SetFillColor(kGreen);
h3p1->SetFillColor(kGreen);
h3p2->SetFillColor(kGreen);
h3p3->SetFillColor(kGreen);

hstack1->Add(h3e);
hstack2->Add(h3x);
hstack3->Add(h3y);
hstack4->Add(h3z);
hstack5->Add(h3p1);
hstack6->Add(h3p2);
hstack7->Add(h3p3);


TCanvas* t1= new TCanvas();
hstack1->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t1->SaveAs("Edep.png");

TCanvas* t2= new TCanvas();
hstack2->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t2->SaveAs("Xgen.png");

TCanvas* t3= new TCanvas();
hstack3->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t3->SaveAs("Ygen.png");

TCanvas* t4= new TCanvas();
hstack4->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t4->SaveAs("Zgen.png");

TCanvas* t5= new TCanvas();
hstack5->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t5->SaveAs("PMT1.png");

TCanvas* t6= new TCanvas();
hstack6->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t6->SaveAs("PMT2.png");

TCanvas* t7= new TCanvas();
hstack7->Draw();
gPad->BuildLegend(0.75, 0.75, 0.95, 0.95, "");
t7->SaveAs("PMT3.png");

}

