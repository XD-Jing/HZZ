#include <xAODTruth/TruthParticle.h>
#include <xAODTruth/TruthParticleContainer.h>


bool CheckFromZ(const xAOD::TruthParticle* trPart, int PDG){
    const xAOD::TruthParticle *parent = trPart->parent();
    if (!parent) return false;
    if (parent->pdgId()==PDG) return CheckFromZ(parent, PDG);
    if (parent->pdgId()==23) return true;
    else return false;
}
