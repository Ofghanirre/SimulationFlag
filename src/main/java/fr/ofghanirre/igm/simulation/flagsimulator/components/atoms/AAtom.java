package fr.ofghanirre.igm.simulation.flagsimulator.components.atoms;

import fr.ofghanirre.igm.simulation.flagsimulator.components.IDisplayable;
import fr.ofghanirre.igm.simulation.flagsimulator.components.IStateRefreshable;
import org.joml.Vector3d;
import org.joml.Vector3f;

public abstract class AAtom implements IDisplayable, IStateRefreshable {
    protected final double mass;
    protected final EAtomType type;
    protected Vector3d position;
    protected Vector3d velocity;
    protected Vector3d force;
    protected Vector3f color;

    public AAtom(double mass, EAtomType type, Vector3d position, Vector3d velocity, Vector3f color) {
        this.mass = mass;
        this.type = type;
        this.position = position;
        this.velocity = velocity;
        this.force = new Vector3d(0d); // Security Rule
        this.color = color;
    }
}
