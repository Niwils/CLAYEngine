/**
 * The CLAYEngine project.
 *
 * @file /src/engine/transportation/Transporter.h
 *
 * @brief Defines the rules structures for transportation units.
 */

/*
 * CHANGELOG:
 * 18/12/2020: File creation (NG)
 */

#ifndef FACTORYBUILDER_TRANSPORTATION_H
#define FACTORYBUILDER_TRANSPORTATION_H

typedef struct
{
    s_NumberofRounds m_nbTicksToLoad;
    s_NumberofRounds m_nbTicksToCrossATile;
    s_NumberofRounds m_nbTicksToUnload;
} TransporterDefinition; ///< Defines the number of rounds required for each action the Transporter performs.

#endif //FACTORYBUILDER_TRANSPORTATION_H
