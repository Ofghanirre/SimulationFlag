package fr.ofghanirre.igm.simulation.flagsimulator.components.links;

import fr.ofghanirre.igm.simulation.flagsimulator.components.IDisplayable;
import fr.ofghanirre.igm.simulation.flagsimulator.components.IStateRefreshable;
import fr.ofghanirre.igm.simulation.flagsimulator.components.atoms.AAtom;

public abstract class ALinks implements IDisplayable, IStateRefreshable {
    protected final AAtom fst;       // Atoms first linked
    protected final AAtom snd;       // Atoms second linked
    protected final ELinkType type;
    protected ALinks(AAtom fst, AAtom snd, ELinkType type) {
        this.fst = fst;
        this.snd = snd;
        this.type = type;
    }
}
