<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\SigmaRaw;

use PHPExiftool\Driver\AbstractTag;

class SceneCaptureType extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'SceneCaptureType';

    protected $FullName = 'mixed';

    protected $GroupName = 'SigmaRaw';

    protected $g0 = 'SigmaRaw';

    protected $g1 = 'SigmaRaw';

    protected $g2 = 'mixed';

    protected $Type = 'mixed';

    protected $Writable = false;

    protected $Description = 'Scene Capture Type';

    protected $MaxLength = 32;

}
