# Algorithm Practice Repository

This repository organizes algorithm practice material into independently usable units while retaining topic- and source-based navigation.

## Language

**Exercise**:
The repository's smallest self-contained practice unit: one problem or reusable implementation together with the material needed to understand and verify it.
_Avoid_: Question, problem target, category executable

**Problem Exercise**:
An Exercise based on an externally specified problem, retaining that problem's identity and native public interface.
_Avoid_: Template Exercise, generic template

**Template Exercise**:
A reusable algorithm, data structure, or reference implementation developed without an external problem identity. The term covers both general practice templates and C++ template-based implementations.
_Avoid_: Problem Exercise, judge problem

**Exercise ID**:
The globally unique, stable identity of an Exercise. A Problem Exercise derives it from its problem series and external identifier; a Template Exercise derives it from its practice domain and subject.
_Avoid_: Display name, topic path, solution class name

**Exercise Test**:
The sole verification form for an Exercise: a repeatable set of examples that invokes the Exercise through its public interface.
_Avoid_: Runner, demo, interactive verification, source-specific test

**Exercise Support Library**:
Shared types and utilities that reproduce or supplement the environment assumed by Exercises, such as judge-provided list and tree node types. It is supporting material, not an Exercise or a practiced data-structure implementation.
_Avoid_: Exercise, core data structures, data-structure solution
