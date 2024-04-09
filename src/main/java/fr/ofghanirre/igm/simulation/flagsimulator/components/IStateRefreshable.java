package fr.ofghanirre.igm.simulation.flagsimulator.components;

import org.joml.Vector3d;

public interface IStateRefreshable {
    void next(Vector3d movement);
}
