package fr.ofghanirre.igm.simulation.flagsimulator.components.links;

import fr.ofghanirre.igm.simulation.flagsimulator.components.atoms.AAtom;
import org.joml.Vector3d;

public class DampingLink extends ALinks {
    private final double rest_length;    // Initial length of link
    private double elasticity;     // Elasticity of link
    private double damping;        // Coefficient d'amortissement

    public DampingLink(AAtom fst, AAtom snd, double elasticity, double damping) {
        super(fst, snd, ELinkType.DAMPING);
        this.rest_length = fst.getPosition().distance(snd.getPosition());
        this.elasticity = elasticity;
        this.damping = damping;
    }

    @Override
    public void next(Vector3d movement) {
        Vector3d direction = this.fst.getPosition().sub(this.snd.getColor());
        double current_length = this.fst.getPosition().distance(this.snd.getPosition());
        double displacement = current_length - this.rest_length;

        Vector3d elastic_force = direction.div(current_length).mul(displacement * this.elasticity);
        Vector3d relative_velocity = this.snd.getVelocity().sub(this.fst.getVelocity());

        double velocity_normal = relative_velocity.dot(direction) / current_length;
        Vector3d damping_force;
        if (current_length == 0) {
            damping_force = new Vector3d(0d);
        } else {
            damping_force = direction.div(current_length).mul(-this.damping * velocity_normal);
        }
        this.fst.setForce(this.fst.getForce().add(elastic_force.add(damping_force)));
        this.snd.setForce(this.snd.getForce().sub(elastic_force.add(damping_force)));
    }

    @Override
    public void display() {

    }
}
