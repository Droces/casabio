<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Reconyx;

use PHPExiftool\Driver\AbstractTag;

class MotionSensitivity extends AbstractTag
{

    protected $Id = 41;

    protected $Name = 'MotionSensitivity';

    protected $FullName = 'Reconyx::Main';

    protected $GroupName = 'Reconyx';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Reconyx';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Motion Sensitivity';

    protected $flag_Permanent = true;

}