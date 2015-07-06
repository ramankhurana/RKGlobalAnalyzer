echo " Datacard_PASSFAIL_barrel_LoosedbetaIso_LooseMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_barrel_LoosedbetaIso_LooseMVA3EV.txt -m 0 
mv mlfit.root mlfit_barrel_LoosedbetaIso_LooseMVA3EV.root  
echo " Datacard_PASSFAIL_barrel_LoosedbetaIso_MediumMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_barrel_LoosedbetaIso_MediumMVA3EV.txt -m 1 
mv mlfit.root mlfit_barrel_LoosedbetaIso_MediumMVA3EV.root  
echo " Datacard_PASSFAIL_barrel_LoosedbetaIso_TightMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_barrel_LoosedbetaIso_TightMVA3EV.txt -m 2 
mv mlfit.root mlfit_barrel_LoosedbetaIso_TightMVA3EV.root  
echo " Datacard_PASSFAIL_barrel_LoosedbetaIso_VTightMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_barrel_LoosedbetaIso_VTightMVA3EV.txt -m 3 
mv mlfit.root mlfit_barrel_LoosedbetaIso_VTightMVA3EV.root  
echo " Datacard_PASSFAIL_endcap_LoosedbetaIso_LooseMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_endcap_LoosedbetaIso_LooseMVA3EV.txt -m 4 
mv mlfit.root mlfit_endcap_LoosedbetaIso_LooseMVA3EV.root  
echo " Datacard_PASSFAIL_endcap_LoosedbetaIso_MediumMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_endcap_LoosedbetaIso_MediumMVA3EV.txt -m 5 
mv mlfit.root mlfit_endcap_LoosedbetaIso_MediumMVA3EV.root  
echo " Datacard_PASSFAIL_endcap_LoosedbetaIso_TightMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_endcap_LoosedbetaIso_TightMVA3EV.txt -m 6 
mv mlfit.root mlfit_endcap_LoosedbetaIso_TightMVA3EV.root  
echo " Datacard_PASSFAIL_endcap_LoosedbetaIso_VTightMVA3EV.txt  " 
combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_endcap_LoosedbetaIso_VTightMVA3EV.txt -m 7 
mv mlfit.root mlfit_endcap_LoosedbetaIso_VTightMVA3EV.root  
