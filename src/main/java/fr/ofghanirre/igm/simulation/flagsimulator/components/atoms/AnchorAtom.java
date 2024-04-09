package fr.ofghanirre.igm.simulation.flagsimulator.components.atoms;

import org.joml.Vector3d;
import org.joml.Vector3f;

public class AnchorAtom extends AAtom {
    public AnchorAtom(double mass, Vector3d position, Vector3f color) {
        super(mass, EAtomType.ANCHOR, position, new Vector3d(0d), color);
    }

    @Override
    public void display() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void next(Vector3d movement) {
        // Safety mesure
        this.force = new Vector3d(0d);
    }
}
