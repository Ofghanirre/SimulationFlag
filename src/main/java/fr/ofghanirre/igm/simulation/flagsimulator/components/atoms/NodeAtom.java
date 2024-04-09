package fr.ofghanirre.igm.simulation.flagsimulator.components.atoms;

import org.joml.Vector3d;
import org.joml.Vector3f;

public class NodeAtom extends AAtom {
    public NodeAtom(double mass, Vector3d position, Vector3d velocity, Vector3f color) {
        super(mass, EAtomType.ANCHOR, position, velocity, color);
    }

    @Override
    public void display() {

    }

    @Override
    public void next(Vector3d movement) {
        double dt = 0.1; // Pas de temps
        Vector3d acceleration = this.force.div(this.mass);
        // Calcul de la nouvelle position à l'aide de la méthode LeapFrog
        this.position.add((this.velocity.add(acceleration.mul(0.5 * dt)).mul(dt).add(movement)));
        // Mise à jour de la vitesse à mi-chemin entre les anciennes et les nouvelles accélérations
        this.velocity = this.velocity.add(acceleration.add(this.force.div(this.mass))).mul(0.5 * dt);
        // Réinitialisation de la force après avoir été utilisée
        this.force = new Vector3d(0d);
    }
}
